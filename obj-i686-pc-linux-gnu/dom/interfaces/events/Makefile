#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/dom/interfaces/events
VPATH		= /home/txema/work/firefox-20.0+build1/dom/interfaces/events

include $(DEPTH)/config/autoconf.mk

MODULE		= dom
XPIDL_MODULE	= dom_events
GRE_MODULE	= 1

SDK_XPIDLSRCS =                                 \
	nsIDOMEvent.idl				\
	nsIDOMEventTarget.idl			\
	nsIDOMEventListener.idl			\
	nsIDOMMouseEvent.idl			\
	nsIDOMMouseScrollEvent.idl      \
	nsIDOMUIEvent.idl			\
	nsIDOMProgressEvent.idl			\
	$(NULL)

XPIDLSRCS =					\
	nsIDOMNSEvent.idl			\
	nsIDOMDataContainerEvent.idl	\
	nsIDOMKeyEvent.idl			\
	nsIDOMMutationEvent.idl			\
	nsIDOMDragEvent.idl  			\
	nsIDOMDataTransfer.idl  			\
	nsIDOMDOMTransactionEvent.idl  			\
	nsIDOMPopupBlockedEvent.idl		\
	nsIDOMBeforeUnloadEvent.idl		\
	nsIDOMSmartCardEvent.idl                \
	nsIDOMPageTransitionEvent.idl		\
	nsIDOMCommandEvent.idl			\
	nsIDOMMessageEvent.idl			\
	nsIDOMNotifyPaintEvent.idl              \
	nsIDOMNotifyAudioAvailableEvent.idl     \
	nsIDOMPaintRequest.idl			\
	nsIDOMPaintRequestList.idl		\
	nsIDOMSimpleGestureEvent.idl		\
	nsIDOMDeviceLightEvent.idl              \
	nsIDOMDeviceProximityEvent.idl          \
	nsIDOMUserProximityEvent.idl            \
	nsIDOMDeviceOrientationEvent.idl        \
	nsIDOMDeviceMotionEvent.idl		\
	nsIDOMScrollAreaEvent.idl		\
	nsIDOMTransitionEvent.idl		\
	nsIDOMAnimationEvent.idl		\
	nsIDOMPopStateEvent.idl			\
	nsIDOMCloseEvent.idl			\
	nsIDOMTouchEvent.idl			\
	nsIDOMHashChangeEvent.idl		\
	nsIDOMCustomEvent.idl			\
	nsIDOMCompositionEvent.idl		\
	nsIDOMWheelEvent.idl			\
	$(NULL)

include $(topsrcdir)/config/rules.mk

XPIDL_FLAGS += \
  -I$(topsrcdir)/dom/interfaces/base \
  $(NULL)
