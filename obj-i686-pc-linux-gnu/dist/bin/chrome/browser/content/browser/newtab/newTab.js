/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

"use strict";

let Cu = Components.utils;
let Ci = Components.interfaces;

Cu.import("resource://gre/modules/XPCOMUtils.jsm");
Cu.import("resource://gre/modules/Services.jsm");
Cu.import("resource:///modules/PageThumbs.jsm");
Cu.import("resource:///modules/NewTabUtils.jsm");

XPCOMUtils.defineLazyModuleGetter(this, "Rect",
  "resource://gre/modules/Geometry.jsm");
XPCOMUtils.defineLazyModuleGetter(this, "PrivateBrowsingUtils",
  "resource://gre/modules/PrivateBrowsingUtils.jsm");

let {
  links: gLinks,
  allPages: gAllPages,
  linkChecker: gLinkChecker,
  pinnedLinks: gPinnedLinks,
  blockedLinks: gBlockedLinks,
  gridPrefs: gGridPrefs
} = NewTabUtils;

XPCOMUtils.defineLazyGetter(this, "gStringBundle", function() {
  return Services.strings.
    createBundle("chrome://browser/locale/newTab.properties");
});

function newTabString(name) gStringBundle.GetStringFromName('newtab.' + name);

function inPrivateBrowsingMode() {
  return PrivateBrowsingUtils.isWindowPrivate(window);
}

const HTML_NAMESPACE = "http://www.w3.org/1999/xhtml";

//@line 6 "/home/txema/work/firefox-20.0+build1/browser/base/content/newtab/batch.js"

/**
 * This class makes it easy to wait until a batch of callbacks has finished.
 *
 * Example:
 *
 * let batch = new Batch(function () alert("finished"));
 * let pop = batch.pop.bind(batch);
 *
 * for (let i = 0; i < 5; i++) {
 *   batch.push();
 *   setTimeout(pop, i * 1000);
 * }
 *
 * batch.close();
 */
function Batch(aCallback) {
  this._callback = aCallback;
}

Batch.prototype = {
  /**
   * The number of batch entries.
   */
  _count: 0,

  /**
   * Whether this batch is closed.
   */
  _closed: false,

  /**
   * Increases the number of batch entries by one.
   */
  push: function Batch_push() {
    if (!this._closed)
      this._count++;
  },

  /**
   * Decreases the number of batch entries by one.
   */
  pop: function Batch_pop() {
    if (this._count)
      this._count--;

    if (this._closed)
      this._check();
  },

  /**
   * Closes the batch so that no new entries can be added.
   */
  close: function Batch_close() {
    if (this._closed)
      return;

    this._closed = true;
    this._check();
  },

  /**
   * Checks if the batch has finished.
   */
  _check: function Batch_check() {
    if (this._count == 0 && this._callback) {
      this._callback();
      this._callback = null;
    }
  }
};
//@line 6 "/home/txema/work/firefox-20.0+build1/browser/base/content/newtab/transformations.js"

/**
 * This singleton allows to transform the grid by repositioning a site's node
 * in the DOM and by showing or hiding the node. It additionally provides
 * convenience methods to work with a site's DOM node.
 */
let gTransformation = {
  /**
   * Returns the width of the left and top border of a cell. We need to take it
   * into account when measuring and comparing site and cell positions.
   */
  get _cellBorderWidths() {
    let cstyle = window.getComputedStyle(gGrid.cells[0].node, null);
    let widths = {
      left: parseInt(cstyle.getPropertyValue("border-left-width")),
      top: parseInt(cstyle.getPropertyValue("border-top-width"))
    };

    // Cache this value, overwrite the getter.
    Object.defineProperty(this, "_cellBorderWidths",
                          {value: widths, enumerable: true});

    return widths;
  },

  /**
   * Gets a DOM node's position.
   * @param aNode The DOM node.
   * @return A Rect instance with the position.
   */
  getNodePosition: function Transformation_getNodePosition(aNode) {
    let {left, top, width, height} = aNode.getBoundingClientRect();
    return new Rect(left + scrollX, top + scrollY, width, height);
  },

  /**
   * Fades a given node from zero to full opacity.
   * @param aNode The node to fade.
   * @param aCallback The callback to call when finished.
   */
  fadeNodeIn: function Transformation_fadeNodeIn(aNode, aCallback) {
    this._setNodeOpacity(aNode, 1, function () {
      // Clear the style property.
      aNode.style.opacity = "";

      if (aCallback)
        aCallback();
    });
  },

  /**
   * Fades a given node from full to zero opacity.
   * @param aNode The node to fade.
   * @param aCallback The callback to call when finished.
   */
  fadeNodeOut: function Transformation_fadeNodeOut(aNode, aCallback) {
    this._setNodeOpacity(aNode, 0, aCallback);
  },

  /**
   * Fades a given site from zero to full opacity.
   * @param aSite The site to fade.
   * @param aCallback The callback to call when finished.
   */
  showSite: function Transformation_showSite(aSite, aCallback) {
    this.fadeNodeIn(aSite.node, aCallback);
  },

  /**
   * Fades a given site from full to zero opacity.
   * @param aSite The site to fade.
   * @param aCallback The callback to call when finished.
   */
  hideSite: function Transformation_hideSite(aSite, aCallback) {
    this.fadeNodeOut(aSite.node, aCallback);
  },

  /**
   * Allows to set a site's position.
   * @param aSite The site to re-position.
   * @param aPosition The desired position for the given site.
   */
  setSitePosition: function Transformation_setSitePosition(aSite, aPosition) {
    let style = aSite.node.style;
    let {top, left} = aPosition;

    style.top = top + "px";
    style.left = left + "px";
  },

  /**
   * Freezes a site in its current position by positioning it absolute.
   * @param aSite The site to freeze.
   */
  freezeSitePosition: function Transformation_freezeSitePosition(aSite) {
    if (this._isFrozen(aSite))
      return;

    let style = aSite.node.style;
    let comp = getComputedStyle(aSite.node, null);
    style.width = comp.getPropertyValue("width")
    style.height = comp.getPropertyValue("height");

    aSite.node.setAttribute("frozen", "true");
    this.setSitePosition(aSite, this.getNodePosition(aSite.node));
  },

  /**
   * Unfreezes a site by removing its absolute positioning.
   * @param aSite The site to unfreeze.
   */
  unfreezeSitePosition: function Transformation_unfreezeSitePosition(aSite) {
    if (!this._isFrozen(aSite))
      return;

    let style = aSite.node.style;
    style.left = style.top = style.width = style.height = "";
    aSite.node.removeAttribute("frozen");
  },

  /**
   * Slides the given site to the target node's position.
   * @param aSite The site to move.
   * @param aTarget The slide target.
   * @param aOptions Set of options (see below).
   *        unfreeze - unfreeze the site after sliding
   *        callback - the callback to call when finished
   */
  slideSiteTo: function Transformation_slideSiteTo(aSite, aTarget, aOptions) {
    let currentPosition = this.getNodePosition(aSite.node);
    let targetPosition = this.getNodePosition(aTarget.node)
    let callback = aOptions && aOptions.callback;

    let self = this;

    function finish() {
      if (aOptions && aOptions.unfreeze)
        self.unfreezeSitePosition(aSite);

      if (callback)
        callback();
    }

    // We need to take the width of a cell's border into account.
    targetPosition.left += this._cellBorderWidths.left;
    targetPosition.top += this._cellBorderWidths.top;

    // Nothing to do here if the positions already match.
    if (currentPosition.left == targetPosition.left &&
        currentPosition.top == targetPosition.top) {
      finish();
    } else {
      this.setSitePosition(aSite, targetPosition);
      this._whenTransitionEnded(aSite.node, finish);
    }
  },

  /**
   * Rearranges a given array of sites and moves them to their new positions or
   * fades in/out new/removed sites.
   * @param aSites An array of sites to rearrange.
   * @param aOptions Set of options (see below).
   *        unfreeze - unfreeze the site after rearranging
   *        callback - the callback to call when finished
   */
  rearrangeSites: function Transformation_rearrangeSites(aSites, aOptions) {
    let batch;
    let cells = gGrid.cells;
    let callback = aOptions && aOptions.callback;
    let unfreeze = aOptions && aOptions.unfreeze;

    if (callback) {
      batch = new Batch(callback);
      callback = function () batch.pop();
    }

    aSites.forEach(function (aSite, aIndex) {
      // Do not re-arrange empty cells or the dragged site.
      if (!aSite || aSite == gDrag.draggedSite)
        return;

      if (batch)
        batch.push();

      if (!cells[aIndex])
        // The site disappeared from the grid, hide it.
        this.hideSite(aSite, callback);
      else if (this._getNodeOpacity(aSite.node) != 1)
        // The site disappeared before but is now back, show it.
        this.showSite(aSite, callback);
      else
        // The site's position has changed, move it around.
        this._moveSite(aSite, aIndex, {unfreeze: unfreeze, callback: callback});
    }, this);

    if (batch)
      batch.close();
  },

  /**
   * Listens for the 'transitionend' event on a given node and calls the given
   * callback.
   * @param aNode The node that is transitioned.
   * @param aCallback The callback to call when finished.
   */
  _whenTransitionEnded:
    function Transformation_whenTransitionEnded(aNode, aCallback) {

    aNode.addEventListener("transitionend", function onEnd() {
      aNode.removeEventListener("transitionend", onEnd, false);
      aCallback();
    }, false);
  },

  /**
   * Gets a given node's opacity value.
   * @param aNode The node to get the opacity value from.
   * @return The node's opacity value.
   */
  _getNodeOpacity: function Transformation_getNodeOpacity(aNode) {
    let cstyle = window.getComputedStyle(aNode, null);
    return cstyle.getPropertyValue("opacity");
  },

  /**
   * Sets a given node's opacity.
   * @param aNode The node to set the opacity value for.
   * @param aOpacity The opacity value to set.
   * @param aCallback The callback to call when finished.
   */
  _setNodeOpacity:
    function Transformation_setNodeOpacity(aNode, aOpacity, aCallback) {

    if (this._getNodeOpacity(aNode) == aOpacity) {
      if (aCallback)
        aCallback();
    } else {
      if (aCallback)
        this._whenTransitionEnded(aNode, aCallback);

      aNode.style.opacity = aOpacity;
    }
  },

  /**
   * Moves a site to the cell with the given index.
   * @param aSite The site to move.
   * @param aIndex The target cell's index.
   * @param aOptions Options that are directly passed to slideSiteTo().
   */
  _moveSite: function Transformation_moveSite(aSite, aIndex, aOptions) {
    this.freezeSitePosition(aSite);
    this.slideSiteTo(aSite, gGrid.cells[aIndex], aOptions);
  },

  /**
   * Checks whether a site is currently frozen.
   * @param aSite The site to check.
   * @return Whether the given site is frozen.
   */
  _isFrozen: function Transformation_isFrozen(aSite) {
    return aSite.node.hasAttribute("frozen");
  }
};
//@line 6 "/home/txema/work/firefox-20.0+build1/browser/base/content/newtab/page.js"

/**
 * This singleton represents the whole 'New Tab Page' and takes care of
 * initializing all its components.
 */
let gPage = {
  /**
   * Initializes the page.
   */
  init: function Page_init() {
    // Add ourselves to the list of pages to receive notifications.
    gAllPages.register(this);

    // Listen for 'unload' to unregister this page.
    addEventListener("unload", this, false);

    // Listen for toggle button clicks.
    let button = document.getElementById("newtab-toggle");
    button.addEventListener("click", this, false);

    // Check if the new tab feature is enabled.
    let enabled = gAllPages.enabled;
    if (enabled)
      this._init();

    this._updateAttributes(enabled);
  },

  /**
   * Listens for notifications specific to this page.
   */
  observe: function Page_observe() {
    let enabled = gAllPages.enabled;
    this._updateAttributes(enabled);

    // Initialize the whole page if we haven't done that, yet.
    if (enabled)
      this._init();
  },

  /**
   * Updates the whole page and the grid when the storage has changed.
   */
  update: function Page_update() {
    gGrid.refresh();
  },

  /**
   * Internally initializes the page. This runs only when/if the feature
   * is/gets enabled.
   */
  _init: function Page_init() {
    if (this._initialized)
      return;

    this._initialized = true;

    gLinks.populateCache(function () {
      // Initialize and render the grid.
      gGrid.init();

      // Initialize the drop target shim.
      gDropTargetShim.init();

//@line 75 "/home/txema/work/firefox-20.0+build1/browser/base/content/newtab/page.js"
    }.bind(this));
  },

  /**
   * Updates the 'page-disabled' attributes of the respective DOM nodes.
   * @param aValue Whether the New Tab Page is enabled or not.
   */
  _updateAttributes: function Page_updateAttributes(aValue) {
    // Set the nodes' states.
    let nodeSelector = "#newtab-scrollbox, #newtab-toggle, #newtab-grid";
    for (let node of document.querySelectorAll(nodeSelector)) {
      if (aValue)
        node.removeAttribute("page-disabled");
      else
        node.setAttribute("page-disabled", "true");
    }

    // Enables/disables the control and link elements.
    let inputSelector = ".newtab-control, .newtab-link";
    for (let input of document.querySelectorAll(inputSelector)) {
      if (aValue) 
        input.removeAttribute("tabindex");
      else
        input.setAttribute("tabindex", "-1");
    }

    // Update the toggle button's title.
    let toggle = document.getElementById("newtab-toggle");
    toggle.setAttribute("title", newTabString(aValue ? "hide" : "show"));
  },

  /**
   * Handles all page events.
   */
  handleEvent: function Page_handleEvent(aEvent) {
    switch (aEvent.type) {
      case "unload":
        gAllPages.unregister(this);
        break;
      case "click":
        gAllPages.enabled = !gAllPages.enabled;
        break;
      case "dragover":
        if (gDrag.isValid(aEvent) && gDrag.draggedSite)
          aEvent.preventDefault();
        break;
      case "drop":
        if (gDrag.isValid(aEvent) && gDrag.draggedSite) {
          aEvent.preventDefault();
          aEvent.stopPropagation();
        }
        break;
    }
  }
};
//@line 6 "/home/txema/work/firefox-20.0+build1/browser/base/content/newtab/grid.js"

/**
 * This singleton represents the grid that contains all sites.
 */
let gGrid = {
  /**
   * The DOM node of the grid.
   */
  _node: null,
  get node() this._node,

  /**
   * The cached DOM fragment for sites.
   */
  _siteFragment: null,

  /**
   * All cells contained in the grid.
   */
  _cells: null,
  get cells() this._cells,

  /**
   * All sites contained in the grid's cells. Sites may be empty.
   */
  get sites() [cell.site for each (cell in this.cells)],

  /**
   * Initializes the grid.
   * @param aSelector The query selector of the grid.
   */
  init: function Grid_init() {
    this._node = document.getElementById("newtab-grid");
    this._createSiteFragment();
    this._render();
  },

  /**
   * Creates a new site in the grid.
   * @param aLink The new site's link.
   * @param aCell The cell that will contain the new site.
   * @return The newly created site.
   */
  createSite: function Grid_createSite(aLink, aCell) {
    let node = aCell.node;
    node.appendChild(this._siteFragment.cloneNode(true));
    return new Site(node.firstElementChild, aLink);
  },

  /**
   * Refreshes the grid and re-creates all sites.
   */
  refresh: function Grid_refresh() {
    // Remove all sites.
    this.cells.forEach(function (cell) {
      let node = cell.node;
      let child = node.firstElementChild;

      if (child)
        node.removeChild(child);
    }, this);

    // Render the grid again.
    this._render();
  },

  /**
   * Locks the grid to block all pointer events.
   */
  lock: function Grid_lock() {
    this.node.setAttribute("locked", "true");
  },

  /**
   * Unlocks the grid to allow all pointer events.
   */
  unlock: function Grid_unlock() {
    this.node.removeAttribute("locked");
  },

  /**
   * Creates the newtab grid.
   */
  _renderGrid: function Grid_renderGrid() {
    let row = document.createElementNS(HTML_NAMESPACE, "div");
    let cell = document.createElementNS(HTML_NAMESPACE, "div");
    row.classList.add("newtab-row");
    cell.classList.add("newtab-cell");

    // Clear the grid
    this._node.innerHTML = "";

    // Creates the structure of one row
    for (let i = 0; i < gGridPrefs.gridColumns; i++) {
      row.appendChild(cell.cloneNode(true));
    }
    // Creates the grid
    for (let j = 0; j < gGridPrefs.gridRows; j++) {
      this._node.appendChild(row.cloneNode(true));
    }

    // (Re-)initialize all cells.
    let cellElements = this.node.querySelectorAll(".newtab-cell");
    this._cells = [new Cell(this, cell) for (cell of cellElements)];
  },

  /**
   * Creates the DOM fragment that is re-used when creating sites.
   */
  _createSiteFragment: function Grid_createSiteFragment() {
    let site = document.createElementNS(HTML_NAMESPACE, "div");
    site.classList.add("newtab-site");
    site.setAttribute("draggable", "true");

    // Create the site's inner HTML code.
    site.innerHTML =
      '<a class="newtab-link">' +
      '  <span class="newtab-thumbnail"/>' +
      '  <span class="newtab-title"/>' +
      '</a>' +
      '<input type="button" title="' + newTabString("pin") + '"' +
      '       class="newtab-control newtab-control-pin"/>' +
      '<input type="button" title="' + newTabString("block") + '"' +
      '       class="newtab-control newtab-control-block"/>';

    this._siteFragment = document.createDocumentFragment();
    this._siteFragment.appendChild(site);
  },

  /**
   * Renders the sites, creates all sites and puts them into their cells.
   */
  _renderSites: function Grid_renderSites() {
    let cells = this.cells;
    // Put sites into the cells.
    let links = gLinks.getLinks();
    let length = Math.min(links.length, cells.length);

    for (let i = 0; i < length; i++) {
      if (links[i])
        this.createSite(links[i], cells[i]);
    }
  },

  /**
   * Renders the grid.
   */
  _render: function Grid_render() {
    if (this._shouldRenderGrid()) {
      this._renderGrid();
    }

    this._renderSites();
  },

  _shouldRenderGrid : function Grid_shouldRenderGrid() {
    let rowsLength = this._node.querySelectorAll(".newtab-row").length;
    let cellsLength = this._node.querySelectorAll(".newtab-cell").length;

    return (rowsLength != gGridPrefs.gridRows ||
            cellsLength != (gGridPrefs.gridRows * gGridPrefs.gridColumns));
  }
};
//@line 6 "/home/txema/work/firefox-20.0+build1/browser/base/content/newtab/cells.js"

/**
 * This class manages a cell's DOM node (not the actually cell content, a site).
 * It's mostly read-only, i.e. all manipulation of both position and content
 * aren't handled here.
 */
function Cell(aGrid, aNode) {
  this._grid = aGrid;
  this._node = aNode;
  this._node._newtabCell = this;

  // Register drag-and-drop event handlers.
  ["dragenter", "dragover", "dragexit", "drop"].forEach(function (aType) {
    this._node.addEventListener(aType, this, false);
  }, this);
}

Cell.prototype = {
  /**
   * The grid.
   */
  _grid: null,

  /**
   * The cell's DOM node.
   */
  get node() this._node,

  /**
   * The cell's offset in the grid.
   */
  get index() {
    let index = this._grid.cells.indexOf(this);

    // Cache this value, overwrite the getter.
    Object.defineProperty(this, "index", {value: index, enumerable: true});

    return index;
  },

  /**
   * The previous cell in the grid.
   */
  get previousSibling() {
    let prev = this.node.previousElementSibling;
    prev = prev && prev._newtabCell;

    // Cache this value, overwrite the getter.
    Object.defineProperty(this, "previousSibling", {value: prev, enumerable: true});

    return prev;
  },

  /**
   * The next cell in the grid.
   */
  get nextSibling() {
    let next = this.node.nextElementSibling;
    next = next && next._newtabCell;

    // Cache this value, overwrite the getter.
    Object.defineProperty(this, "nextSibling", {value: next, enumerable: true});

    return next;
  },

  /**
   * The site contained in the cell, if any.
   */
  get site() {
    let firstChild = this.node.firstElementChild;
    return firstChild && firstChild._newtabSite;
  },

  /**
   * Checks whether the cell contains a pinned site.
   * @return Whether the cell contains a pinned site.
   */
  containsPinnedSite: function Cell_containsPinnedSite() {
    let site = this.site;
    return site && site.isPinned();
  },

  /**
   * Checks whether the cell contains a site (is empty).
   * @return Whether the cell is empty.
   */
  isEmpty: function Cell_isEmpty() {
    return !this.site;
  },

  /**
   * Handles all cell events.
   */
  handleEvent: function Cell_handleEvent(aEvent) {
    // We're not responding to external drag/drop events
    // when our parent window is in private browsing mode.
    if (inPrivateBrowsingMode() && !gDrag.draggedSite)
      return;

    if (aEvent.type != "dragexit" && !gDrag.isValid(aEvent))
      return;

    switch (aEvent.type) {
      case "dragenter":
        aEvent.preventDefault();
        gDrop.enter(this, aEvent);
        break;
      case "dragover":
        aEvent.preventDefault();
        break;
      case "dragexit":
        gDrop.exit(this, aEvent);
        break;
      case "drop":
        aEvent.preventDefault();
        gDrop.drop(this, aEvent);
        break;
    }
  }
};
//@line 6 "/home/txema/work/firefox-20.0+build1/browser/base/content/newtab/sites.js"

/**
 * This class represents a site that is contained in a cell and can be pinned,
 * moved around or deleted.
 */
function Site(aNode, aLink) {
  this._node = aNode;
  this._node._newtabSite = this;

  this._link = aLink;

  this._render();
  this._addEventHandlers();
}

Site.prototype = {
  /**
   * The site's DOM node.
   */
  get node() this._node,

  /**
   * The site's link.
   */
  get link() this._link,

  /**
   * The url of the site's link.
   */
  get url() this.link.url,

  /**
   * The title of the site's link.
   */
  get title() this.link.title,

  /**
   * The site's parent cell.
   */
  get cell() {
    let parentNode = this.node.parentNode;
    return parentNode && parentNode._newtabCell;
  },

  /**
   * Pins the site on its current or a given index.
   * @param aIndex The pinned index (optional).
   */
  pin: function Site_pin(aIndex) {
    if (typeof aIndex == "undefined")
      aIndex = this.cell.index;

    this._updateAttributes(true);
    gPinnedLinks.pin(this._link, aIndex);
  },

  /**
   * Unpins the site and calls the given callback when done.
   */
  unpin: function Site_unpin() {
    if (this.isPinned()) {
      this._updateAttributes(false);
      gPinnedLinks.unpin(this._link);
      gUpdater.updateGrid();
    }
  },

  /**
   * Checks whether this site is pinned.
   * @return Whether this site is pinned.
   */
  isPinned: function Site_isPinned() {
    return gPinnedLinks.isPinned(this._link);
  },

  /**
   * Blocks the site (removes it from the grid) and calls the given callback
   * when done.
   */
  block: function Site_block() {
    if (!gBlockedLinks.isBlocked(this._link)) {
      gBlockedLinks.block(this._link);
      gUpdater.updateGrid();
    }
  },

  /**
   * Gets the DOM node specified by the given query selector.
   * @param aSelector The query selector.
   * @return The DOM node we found.
   */
  _querySelector: function Site_querySelector(aSelector) {
    return this.node.querySelector(aSelector);
  },

  /**
   * Updates attributes for all nodes which status depends on this site being
   * pinned or unpinned.
   * @param aPinned Whether this site is now pinned or unpinned.
   */
  _updateAttributes: function (aPinned) {
    let control = this._querySelector(".newtab-control-pin");

    if (aPinned) {
      control.setAttribute("pinned", true);
      control.setAttribute("title", newTabString("unpin"));
    } else {
      control.removeAttribute("pinned");
      control.setAttribute("title", newTabString("pin"));
    }
  },

  /**
   * Renders the site's data (fills the HTML fragment).
   */
  _render: function Site_render() {
    let url = this.url;
    let title = this.title || url;
    let tooltip = (title == url ? title : title + "\n" + url);

    let link = this._querySelector(".newtab-link");
    link.setAttribute("title", tooltip);
    link.setAttribute("href", url);
    this._querySelector(".newtab-title").textContent = title;

    if (this.isPinned())
      this._updateAttributes(true);

    let thumbnailURL = PageThumbs.getThumbnailURL(this.url);
    let thumbnail = this._querySelector(".newtab-thumbnail");
    thumbnail.style.backgroundImage = "url(" + thumbnailURL + ")";
  },

  /**
   * Adds event handlers for the site and its buttons.
   */
  _addEventHandlers: function Site_addEventHandlers() {
    // Register drag-and-drop event handlers.
    this._node.addEventListener("dragstart", this, false);
    this._node.addEventListener("dragend", this, false);

    let controls = this.node.querySelectorAll(".newtab-control");
    for (let i = 0; i < controls.length; i++)
      controls[i].addEventListener("click", this, false);
  },

  /**
   * Handles all site events.
   */
  handleEvent: function Site_handleEvent(aEvent) {
    switch (aEvent.type) {
      case "click":
        aEvent.preventDefault();
        if (aEvent.target.classList.contains("newtab-control-block"))
          this.block();
        else if (this.isPinned())
          this.unpin();
        else
          this.pin();
        break;
      case "dragstart":
        gDrag.start(this, aEvent);
        break;
      case "drag":
        gDrag.drag(this, aEvent);
        break;
      case "dragend":
        gDrag.end(this, aEvent);
        break;
    }
  }
};
//@line 6 "/home/txema/work/firefox-20.0+build1/browser/base/content/newtab/drag.js"

/**
 * This singleton implements site dragging functionality.
 */
let gDrag = {
  /**
   * The site offset to the drag start point.
   */
  _offsetX: null,
  _offsetY: null,

  /**
   * The site that is dragged.
   */
  _draggedSite: null,
  get draggedSite() this._draggedSite,

  /**
   * The cell width/height at the point the drag started.
   */
  _cellWidth: null,
  _cellHeight: null,
  get cellWidth() this._cellWidth,
  get cellHeight() this._cellHeight,

  /**
   * Start a new drag operation.
   * @param aSite The site that's being dragged.
   * @param aEvent The 'dragstart' event.
   */
  start: function Drag_start(aSite, aEvent) {
    this._draggedSite = aSite;

    // Mark nodes as being dragged.
    let selector = ".newtab-site, .newtab-control, .newtab-thumbnail";
    let parentCell = aSite.node.parentNode;
    let nodes = parentCell.querySelectorAll(selector);
    for (let i = 0; i < nodes.length; i++)
      nodes[i].setAttribute("dragged", "true");

    parentCell.setAttribute("dragged", "true");

    this._setDragData(aSite, aEvent);

    // Store the cursor offset.
    let node = aSite.node;
    let rect = node.getBoundingClientRect();
    this._offsetX = aEvent.clientX - rect.left;
    this._offsetY = aEvent.clientY - rect.top;

    // Store the cell dimensions.
    let cellNode = aSite.cell.node;
    this._cellWidth = cellNode.offsetWidth;
    this._cellHeight = cellNode.offsetHeight;

    gTransformation.freezeSitePosition(aSite);
  },

  /**
   * Handles the 'drag' event.
   * @param aSite The site that's being dragged.
   * @param aEvent The 'drag' event.
   */
  drag: function Drag_drag(aSite, aEvent) {
    // Get the viewport size.
    let {clientWidth, clientHeight} = document.documentElement;

    // We'll want a padding of 5px.
    let border = 5;

    // Enforce minimum constraints to keep the drag image inside the window.
    let left = Math.max(scrollX + aEvent.clientX - this._offsetX, border);
    let top = Math.max(scrollY + aEvent.clientY - this._offsetY, border);

    // Enforce maximum constraints to keep the drag image inside the window.
    left = Math.min(left, scrollX + clientWidth - this.cellWidth - border);
    top = Math.min(top, scrollY + clientHeight - this.cellHeight - border);

    // Update the drag image's position.
    gTransformation.setSitePosition(aSite, {left: left, top: top});
  },

  /**
   * Ends the current drag operation.
   * @param aSite The site that's being dragged.
   * @param aEvent The 'dragend' event.
   */
  end: function Drag_end(aSite, aEvent) {
    let nodes = gGrid.node.querySelectorAll("[dragged]")
    for (let i = 0; i < nodes.length; i++)
      nodes[i].removeAttribute("dragged");

    // Slide the dragged site back into its cell (may be the old or the new cell).
    gTransformation.slideSiteTo(aSite, aSite.cell, {unfreeze: true});

    this._draggedSite = null;
  },

  /**
   * Checks whether we're responsible for a given drag event.
   * @param aEvent The drag event to check.
   * @return Whether we should handle this drag and drop operation.
   */
  isValid: function Drag_isValid(aEvent) {
    let link = gDragDataHelper.getLinkFromDragEvent(aEvent);

    // Check that the drag data is non-empty.
    // Can happen when dragging places folders.
    if (!link || !link.url) {
      return false;
    }

    // Check that we're not accepting URLs which would inherit the caller's
    // principal (such as javascript: or data:).
    return gLinkChecker.checkLoadURI(link.url);
  },

  /**
   * Initializes the drag data for the current drag operation.
   * @param aSite The site that's being dragged.
   * @param aEvent The 'dragstart' event.
   */
  _setDragData: function Drag_setDragData(aSite, aEvent) {
    let {url, title} = aSite;

    let dt = aEvent.dataTransfer;
    dt.mozCursor = "default";
    dt.effectAllowed = "move";
    dt.setData("text/plain", url);
    dt.setData("text/uri-list", url);
    dt.setData("text/x-moz-url", url + "\n" + title);
    dt.setData("text/html", "<a href=\"" + url + "\">" + url + "</a>");

    // Create and use an empty drag element. We don't want to use the default
    // drag image with its default opacity.
    let dragElement = document.createElementNS(HTML_NAMESPACE, "div");
    dragElement.classList.add("newtab-drag");
    let scrollbox = document.getElementById("newtab-scrollbox");
    scrollbox.appendChild(dragElement);
    dt.setDragImage(dragElement, 0, 0);

    // After the 'dragstart' event has been processed we can remove the
    // temporary drag element from the DOM.
    setTimeout(function () scrollbox.removeChild(dragElement), 0);
  }
};
//@line 6 "/home/txema/work/firefox-20.0+build1/browser/base/content/newtab/dragDataHelper.js"

let gDragDataHelper = {
  get mimeType() {
    return "text/x-moz-url";
  },

  getLinkFromDragEvent: function DragDataHelper_getLinkFromDragEvent(aEvent) {
    let dt = aEvent.dataTransfer;
    if (!dt || !dt.types.contains(this.mimeType)) {
      return null;
    }

    let data = dt.getData(this.mimeType) || "";
    let [url, title] = data.split(/[\r\n]+/);
    return {url: url, title: title};
  }
};
//@line 6 "/home/txema/work/firefox-20.0+build1/browser/base/content/newtab/drop.js"

// A little delay that prevents the grid from being too sensitive when dragging
// sites around.
const DELAY_REARRANGE_MS = 100;

/**
 * This singleton implements site dropping functionality.
 */
let gDrop = {
  /**
   * The last drop target.
   */
  _lastDropTarget: null,

  /**
   * Handles the 'dragenter' event.
   * @param aCell The drop target cell.
   */
  enter: function Drop_enter(aCell) {
    this._delayedRearrange(aCell);
  },

  /**
   * Handles the 'dragexit' event.
   * @param aCell The drop target cell.
   * @param aEvent The 'dragexit' event.
   */
  exit: function Drop_exit(aCell, aEvent) {
    if (aEvent.dataTransfer && !aEvent.dataTransfer.mozUserCancelled) {
      this._delayedRearrange();
    } else {
      // The drag operation has been cancelled.
      this._cancelDelayedArrange();
      this._rearrange();
    }
  },

  /**
   * Handles the 'drop' event.
   * @param aCell The drop target cell.
   * @param aEvent The 'dragexit' event.
   */
  drop: function Drop_drop(aCell, aEvent) {
    // The cell that is the drop target could contain a pinned site. We need
    // to find out where that site has gone and re-pin it there.
    if (aCell.containsPinnedSite())
      this._repinSitesAfterDrop(aCell);

    // Pin the dragged or insert the new site.
    this._pinDraggedSite(aCell, aEvent);

    this._cancelDelayedArrange();

    // Update the grid and move all sites to their new places.
    gUpdater.updateGrid();
  },

  /**
   * Re-pins all pinned sites in their (new) positions.
   * @param aCell The drop target cell.
   */
  _repinSitesAfterDrop: function Drop_repinSitesAfterDrop(aCell) {
    let sites = gDropPreview.rearrange(aCell);

    // Filter out pinned sites.
    let pinnedSites = sites.filter(function (aSite) {
      return aSite && aSite.isPinned();
    });

    // Re-pin all shifted pinned cells.
    pinnedSites.forEach(function (aSite) aSite.pin(sites.indexOf(aSite)), this);
  },

  /**
   * Pins the dragged site in its new place.
   * @param aCell The drop target cell.
   * @param aEvent The 'dragexit' event.
   */
  _pinDraggedSite: function Drop_pinDraggedSite(aCell, aEvent) {
    let index = aCell.index;
    let draggedSite = gDrag.draggedSite;

    if (draggedSite) {
      // Pin the dragged site at its new place.
      if (aCell != draggedSite.cell)
        draggedSite.pin(index);
    } else {
      let link = gDragDataHelper.getLinkFromDragEvent(aEvent);
      if (link) {
        // A new link was dragged onto the grid. Create it by pinning its URL.
        gPinnedLinks.pin(link, index);

        // Make sure the newly added link is not blocked.
        gBlockedLinks.unblock(link);
      }
    }
  },

  /**
   * Time a rearrange with a little delay.
   * @param aCell The drop target cell.
   */
  _delayedRearrange: function Drop_delayedRearrange(aCell) {
    // The last drop target didn't change so there's no need to re-arrange.
    if (this._lastDropTarget == aCell)
      return;

    let self = this;

    function callback() {
      self._rearrangeTimeout = null;
      self._rearrange(aCell);
    }

    this._cancelDelayedArrange();
    this._rearrangeTimeout = setTimeout(callback, DELAY_REARRANGE_MS);

    // Store the last drop target.
    this._lastDropTarget = aCell;
  },

  /**
   * Cancels a timed rearrange, if any.
   */
  _cancelDelayedArrange: function Drop_cancelDelayedArrange() {
    if (this._rearrangeTimeout) {
      clearTimeout(this._rearrangeTimeout);
      this._rearrangeTimeout = null;
    }
  },

  /**
   * Rearrange all sites in the grid depending on the current drop target.
   * @param aCell The drop target cell.
   */
  _rearrange: function Drop_rearrange(aCell) {
    let sites = gGrid.sites;

    // We need to rearrange the grid only if there's a current drop target.
    if (aCell)
      sites = gDropPreview.rearrange(aCell);

    gTransformation.rearrangeSites(sites, {unfreeze: !aCell});
  }
};
//@line 6 "/home/txema/work/firefox-20.0+build1/browser/base/content/newtab/dropTargetShim.js"

/**
 * This singleton provides a custom drop target detection. We need this because
 * the default DnD target detection relies on the cursor's position. We want
 * to pick a drop target based on the dragged site's position.
 */
let gDropTargetShim = {
  /**
   * Cache for the position of all cells, cleaned after drag finished.
   */
  _cellPositions: null,

  /**
   * The last drop target that was hovered.
   */
  _lastDropTarget: null,

  /**
   * Initializes the drop target shim.
   */
  init: function DropTargetShim_init() {
    let node = gGrid.node;

    // Add drag event handlers.
    node.addEventListener("dragstart", this, true);
    node.addEventListener("dragend", this, true);
  },

  /**
   * Handles all shim events.
   */
  handleEvent: function DropTargetShim_handleEvent(aEvent) {
    switch (aEvent.type) {
      case "dragstart":
        this._start(aEvent);
        break;
      case "dragover":
        this._dragover(aEvent);
        break;
      case "dragend":
        this._end(aEvent);
        break;
    }
  },

  /**
   * Handles the 'dragstart' event.
   * @param aEvent The 'dragstart' event.
   */
  _start: function DropTargetShim_start(aEvent) {
    if (aEvent.target.classList.contains("newtab-link")) {
      gGrid.lock();

      // XXX bug 505521 - Listen for dragover on the document.
      document.documentElement.addEventListener("dragover", this, false);
    }
  },

  /**
   * Handles the 'drag' event and determines the current drop target.
   * @param aEvent The 'drag' event.
   */
  _drag: function DropTargetShim_drag(aEvent) {
    // Let's see if we find a drop target.
    let target = this._findDropTarget(aEvent);

    if (target != this._lastDropTarget) {
      if (this._lastDropTarget)
        // We left the last drop target.
        this._dispatchEvent(aEvent, "dragexit", this._lastDropTarget);

      if (target)
        // We're now hovering a (new) drop target.
        this._dispatchEvent(aEvent, "dragenter", target);

      if (this._lastDropTarget)
        // We left the last drop target.
        this._dispatchEvent(aEvent, "dragleave", this._lastDropTarget);

      this._lastDropTarget = target;
    }
  },

  /**
   * Handles the 'dragover' event as long as bug 505521 isn't fixed to get
   * current mouse cursor coordinates while dragging.
   * @param aEvent The 'dragover' event.
   */
  _dragover: function DropTargetShim_dragover(aEvent) {
    let sourceNode = aEvent.dataTransfer.mozSourceNode.parentNode;
    gDrag.drag(sourceNode._newtabSite, aEvent);

    this._drag(aEvent);
  },

  /**
   * Handles the 'dragend' event.
   * @param aEvent The 'dragend' event.
   */
  _end: function DropTargetShim_end(aEvent) {
    // Make sure to determine the current drop target in case the dragenter
    // event hasn't been fired.
    this._drag(aEvent);

    if (this._lastDropTarget) {
      if (aEvent.dataTransfer.mozUserCancelled) {
        // The drag operation was cancelled.
        this._dispatchEvent(aEvent, "dragexit", this._lastDropTarget);
        this._dispatchEvent(aEvent, "dragleave", this._lastDropTarget);
      } else {
        // A site was successfully dropped.
        this._dispatchEvent(aEvent, "drop", this._lastDropTarget);
      }

      // Clean up.
      this._lastDropTarget = null;
      this._cellPositions = null;
    }

    gGrid.unlock();

    // XXX bug 505521 - Remove the document's dragover listener.
    document.documentElement.removeEventListener("dragover", this, false);
  },

  /**
   * Determines the current drop target by matching the dragged site's position
   * against all cells in the grid.
   * @return The currently hovered drop target or null.
   */
  _findDropTarget: function DropTargetShim_findDropTarget() {
    // These are the minimum intersection values - we want to use the cell if
    // the site is >= 50% hovering its position.
    let minWidth = gDrag.cellWidth / 2;
    let minHeight = gDrag.cellHeight / 2;

    let cellPositions = this._getCellPositions();
    let rect = gTransformation.getNodePosition(gDrag.draggedSite.node);

    // Compare each cell's position to the dragged site's position.
    for (let i = 0; i < cellPositions.length; i++) {
      let inter = rect.intersect(cellPositions[i].rect);

      // If the intersection is big enough we found a drop target.
      if (inter.width >= minWidth && inter.height >= minHeight)
        return cellPositions[i].cell;
    }

    // No drop target found.
    return null;
  },

  /**
   * Gets the positions of all cell nodes.
   * @return The (cached) cell positions.
   */
  _getCellPositions: function DropTargetShim_getCellPositions() {
    if (this._cellPositions)
      return this._cellPositions;

    return this._cellPositions = gGrid.cells.map(function (cell) {
      return {cell: cell, rect: gTransformation.getNodePosition(cell.node)};
    });
  },

  /**
   * Dispatches a custom DragEvent on the given target node.
   * @param aEvent The source event.
   * @param aType The event type.
   * @param aTarget The target node that receives the event.
   */
  _dispatchEvent:
    function DropTargetShim_dispatchEvent(aEvent, aType, aTarget) {

    let node = aTarget.node;
    let event = document.createEvent("DragEvents");

    event.initDragEvent(aType, true, true, window, 0, 0, 0, 0, 0, false, false,
                        false, false, 0, node, aEvent.dataTransfer);

    node.dispatchEvent(event);
  }
};
//@line 6 "/home/txema/work/firefox-20.0+build1/browser/base/content/newtab/dropPreview.js"

/**
 * This singleton provides the ability to re-arrange the current grid to
 * indicate the transformation that results from dropping a cell at a certain
 * position.
 */
let gDropPreview = {
  /**
   * Rearranges the sites currently contained in the grid when a site would be
   * dropped onto the given cell.
   * @param aCell The drop target cell.
   * @return The re-arranged array of sites.
   */
  rearrange: function DropPreview_rearrange(aCell) {
    let sites = gGrid.sites;

    // Insert the dragged site into the current grid.
    this._insertDraggedSite(sites, aCell);

    // After the new site has been inserted we need to correct the positions
    // of all pinned tabs that have been moved around.
    this._repositionPinnedSites(sites, aCell);

    return sites;
  },

  /**
   * Inserts the currently dragged site into the given array of sites.
   * @param aSites The array of sites to insert into.
   * @param aCell The drop target cell.
   */
  _insertDraggedSite: function DropPreview_insertDraggedSite(aSites, aCell) {
    let dropIndex = aCell.index;
    let draggedSite = gDrag.draggedSite;

    // We're currently dragging a site.
    if (draggedSite) {
      let dragCell = draggedSite.cell;
      let dragIndex = dragCell.index;

      // Move the dragged site into its new position.
      if (dragIndex != dropIndex) {
        aSites.splice(dragIndex, 1);
        aSites.splice(dropIndex, 0, draggedSite);
      }
    // We're handling an external drag item.
    } else {
      aSites.splice(dropIndex, 0, null);
    }
  },

  /**
   * Correct the position of all pinned sites that might have been moved to
   * different positions after the dragged site has been inserted.
   * @param aSites The array of sites containing the dragged site.
   * @param aCell The drop target cell.
   */
  _repositionPinnedSites:
    function DropPreview_repositionPinnedSites(aSites, aCell) {

    // Collect all pinned sites.
    let pinnedSites = this._filterPinnedSites(aSites, aCell);

    // Correct pinned site positions.
    pinnedSites.forEach(function (aSite) {
      aSites[aSites.indexOf(aSite)] = aSites[aSite.cell.index];
      aSites[aSite.cell.index] = aSite;
    }, this);

    // There might be a pinned cell that got pushed out of the grid, try to
    // sneak it in by removing a lower-priority cell.
    if (this._hasOverflowedPinnedSite(aSites, aCell))
      this._repositionOverflowedPinnedSite(aSites, aCell);
  },

  /**
   * Filter pinned sites out of the grid that are still on their old positions
   * and have not moved.
   * @param aSites The array of sites to filter.
   * @param aCell The drop target cell.
   * @return The filtered array of sites.
   */
  _filterPinnedSites: function DropPreview_filterPinnedSites(aSites, aCell) {
    let draggedSite = gDrag.draggedSite;

    // When dropping on a cell that contains a pinned site make sure that all
    // pinned cells surrounding the drop target are moved as well.
    let range = this._getPinnedRange(aCell);

    return aSites.filter(function (aSite, aIndex) {
      // The site must be valid, pinned and not the dragged site.
      if (!aSite || aSite == draggedSite || !aSite.isPinned())
        return false;

      let index = aSite.cell.index;

      // If it's not in the 'pinned range' it's a valid pinned site.
      return (index > range.end || index < range.start);
    });
  },

  /**
   * Determines the range of pinned sites surrounding the drop target cell.
   * @param aCell The drop target cell.
   * @return The range of pinned cells.
   */
  _getPinnedRange: function DropPreview_getPinnedRange(aCell) {
    let dropIndex = aCell.index;
    let range = {start: dropIndex, end: dropIndex};

    // We need a pinned range only when dropping on a pinned site.
    if (aCell.containsPinnedSite()) {
      let links = gPinnedLinks.links;

      // Find all previous siblings of the drop target that are pinned as well.
      while (range.start && links[range.start - 1])
        range.start--;

      let maxEnd = links.length - 1;

      // Find all next siblings of the drop target that are pinned as well.
      while (range.end < maxEnd && links[range.end + 1])
        range.end++;
    }

    return range;
  },

  /**
   * Checks if the given array of sites contains a pinned site that has
   * been pushed out of the grid.
   * @param aSites The array of sites to check.
   * @param aCell The drop target cell.
   * @return Whether there is an overflowed pinned cell.
   */
  _hasOverflowedPinnedSite:
    function DropPreview_hasOverflowedPinnedSite(aSites, aCell) {

    // If the drop target isn't pinned there's no way a pinned site has been
    // pushed out of the grid so we can just exit here.
    if (!aCell.containsPinnedSite())
      return false;

    let cells = gGrid.cells;

    // No cells have been pushed out of the grid, nothing to do here.
    if (aSites.length <= cells.length)
      return false;

    let overflowedSite = aSites[cells.length];

    // Nothing to do if the site that got pushed out of the grid is not pinned.
    return (overflowedSite && overflowedSite.isPinned());
  },

  /**
   * We have a overflowed pinned site that we need to re-position so that it's
   * visible again. We try to find a lower-priority cell (empty or containing
   * an unpinned site) that we can move it to.
   * @param aSites The array of sites.
   * @param aCell The drop target cell.
   */
  _repositionOverflowedPinnedSite:
    function DropPreview_repositionOverflowedPinnedSite(aSites, aCell) {

    // Try to find a lower-priority cell (empty or containing an unpinned site).
    let index = this._indexOfLowerPrioritySite(aSites, aCell);

    if (index > -1) {
      let cells = gGrid.cells;
      let dropIndex = aCell.index;

      // Move all pinned cells to their new positions to let the overflowed
      // site fit into the grid.
      for (let i = index + 1, lastPosition = index; i < aSites.length; i++) {
        if (i != dropIndex) {
          aSites[lastPosition] = aSites[i];
          lastPosition = i;
        }
      }

      // Finally, remove the overflowed site from its previous position.
      aSites.splice(cells.length, 1);
    }
  },

  /**
   * Finds the index of the last cell that is empty or contains an unpinned
   * site. These are considered to be of a lower priority.
   * @param aSites The array of sites.
   * @param aCell The drop target cell.
   * @return The cell's index.
   */
  _indexOfLowerPrioritySite:
    function DropPreview_indexOfLowerPrioritySite(aSites, aCell) {

    let cells = gGrid.cells;
    let dropIndex = aCell.index;

    // Search (beginning with the last site in the grid) for a site that is
    // empty or unpinned (an thus lower-priority) and can be pushed out of the
    // grid instead of the pinned site.
    for (let i = cells.length - 1; i >= 0; i--) {
      // The cell that is our drop target is not a good choice.
      if (i == dropIndex)
        continue;

      let site = aSites[i];

      // We can use the cell only if it's empty or the site is un-pinned.
      if (!site || !site.isPinned())
        return i;
    }

    return -1;
  }
};
//@line 6 "/home/txema/work/firefox-20.0+build1/browser/base/content/newtab/updater.js"

/**
 * This singleton provides functionality to update the current grid to a new
 * set of pinned and blocked sites. It adds, moves and removes sites.
 */
let gUpdater = {
  /**
   * Updates the current grid according to its pinned and blocked sites.
   * This removes old, moves existing and creates new sites to fill gaps.
   * @param aCallback The callback to call when finished.
   */
  updateGrid: function Updater_updateGrid(aCallback) {
    let links = gLinks.getLinks().slice(0, gGrid.cells.length);

    // Find all sites that remain in the grid.
    let sites = this._findRemainingSites(links);

    let self = this;

    // Remove sites that are no longer in the grid.
    this._removeLegacySites(sites, function () {
      // Freeze all site positions so that we can move their DOM nodes around
      // without any visual impact.
      self._freezeSitePositions(sites);

      // Move the sites' DOM nodes to their new position in the DOM. This will
      // have no visual effect as all the sites have been frozen and will
      // remain in their current position.
      self._moveSiteNodes(sites);

      // Now it's time to animate the sites actually moving to their new
      // positions.
      self._rearrangeSites(sites, function () {
        // Try to fill empty cells and finish.
        self._fillEmptyCells(links, aCallback);

        // Update other pages that might be open to keep them synced.
        gAllPages.update(gPage);
      });
    });
  },

  /**
   * Takes an array of links and tries to correlate them to sites contained in
   * the current grid. If no corresponding site can be found (i.e. the link is
   * new and a site will be created) then just set it to null.
   * @param aLinks The array of links to find sites for.
   * @return Array of sites mapped to the given links (can contain null values).
   */
  _findRemainingSites: function Updater_findRemainingSites(aLinks) {
    let map = {};

    // Create a map to easily retrieve the site for a given URL.
    gGrid.sites.forEach(function (aSite) {
      if (aSite)
        map[aSite.url] = aSite;
    });

    // Map each link to its corresponding site, if any.
    return aLinks.map(function (aLink) {
      return aLink && (aLink.url in map) && map[aLink.url];
    });
  },

  /**
   * Freezes the given sites' positions.
   * @param aSites The array of sites to freeze.
   */
  _freezeSitePositions: function Updater_freezeSitePositions(aSites) {
    aSites.forEach(function (aSite) {
      if (aSite)
        gTransformation.freezeSitePosition(aSite);
    });
  },

  /**
   * Moves the given sites' DOM nodes to their new positions.
   * @param aSites The array of sites to move.
   */
  _moveSiteNodes: function Updater_moveSiteNodes(aSites) {
    let cells = gGrid.cells;

    // Truncate the given array of sites to not have more sites than cells.
    // This can happen when the user drags a bookmark (or any other new kind
    // of link) onto the grid.
    let sites = aSites.slice(0, cells.length);

    sites.forEach(function (aSite, aIndex) {
      let cell = cells[aIndex];
      let cellSite = cell.site;

      // The site's position didn't change.
      if (!aSite || cellSite != aSite) {
        let cellNode = cell.node;

        // Empty the cell if necessary.
        if (cellSite)
          cellNode.removeChild(cellSite.node);

        // Put the new site in place, if any.
        if (aSite)
          cellNode.appendChild(aSite.node);
      }
    }, this);
  },

  /**
   * Rearranges the given sites and slides them to their new positions.
   * @param aSites The array of sites to re-arrange.
   * @param aCallback The callback to call when finished.
   */
  _rearrangeSites: function Updater_rearrangeSites(aSites, aCallback) {
    let options = {callback: aCallback, unfreeze: true};
    gTransformation.rearrangeSites(aSites, options);
  },

  /**
   * Removes all sites from the grid that are not in the given links array or
   * exceed the grid.
   * @param aSites The array of sites remaining in the grid.
   * @param aCallback The callback to call when finished.
   */
  _removeLegacySites: function Updater_removeLegacySites(aSites, aCallback) {
    let batch = new Batch(aCallback);

    // Delete sites that were removed from the grid.
    gGrid.sites.forEach(function (aSite) {
      // The site must be valid and not in the current grid.
      if (!aSite || aSites.indexOf(aSite) != -1)
        return;

      batch.push();

      // Fade out the to-be-removed site.
      gTransformation.hideSite(aSite, function () {
        let node = aSite.node;

        // Remove the site from the DOM.
        node.parentNode.removeChild(node);
        batch.pop();
      });
    });

    batch.close();
  },

  /**
   * Tries to fill empty cells with new links if available.
   * @param aLinks The array of links.
   * @param aCallback The callback to call when finished.
   */
  _fillEmptyCells: function Updater_fillEmptyCells(aLinks, aCallback) {
    let {cells, sites} = gGrid;
    let batch = new Batch(aCallback);

    // Find empty cells and fill them.
    sites.forEach(function (aSite, aIndex) {
      if (aSite || !aLinks[aIndex])
        return;

      batch.push();

      // Create the new site and fade it in.
      let site = gGrid.createSite(aLinks[aIndex], cells[aIndex]);

      // Set the site's initial opacity to zero.
      site.node.style.opacity = 0;

      // Flush all style changes for the dynamically inserted site to make
      // the fade-in transition work.
      window.getComputedStyle(site.node).opacity;
      gTransformation.showSite(site, function () batch.pop());
    });

    batch.close();
  }
};
//@line 54 "/home/txema/work/firefox-20.0+build1/browser/base/content/newtab/newTab.js"

// Everything is loaded. Initialize the New Tab Page.
gPage.init();
