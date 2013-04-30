/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/media/bridge/IPeerConnection.idl
 */

#ifndef __gen_IPeerConnection_h__
#define __gen_IPeerConnection_h__


#ifndef __gen_nsIThread_h__
#include "nsIThread.h"
#endif

#ifndef __gen_nsIDOMWindow_h__
#include "nsIDOMWindow.h"
#endif

#ifndef __gen_nsIPropertyBag2_h__
#include "nsIPropertyBag2.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMMediaStream; /* forward declaration */

class nsIDOMDataChannel; /* forward declaration */


/* starting interface:    IPeerConnectionManager */
#define IPEERCONNECTIONMANAGER_IID_STR "c2218bd2-2648-4701-8fa6-305d3379e9f8"

#define IPEERCONNECTIONMANAGER_IID \
  {0xc2218bd2, 0x2648, 0x4701, \
    { 0x8f, 0xa6, 0x30, 0x5d, 0x33, 0x79, 0xe9, 0xf8 }}

class NS_NO_VTABLE IPeerConnectionManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IPEERCONNECTIONMANAGER_IID)

  /* boolean hasActivePeerConnection (in unsigned long innerWindowID); */
  NS_IMETHOD HasActivePeerConnection(uint32_t innerWindowID, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(IPeerConnectionManager, IPEERCONNECTIONMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_IPEERCONNECTIONMANAGER \
  NS_IMETHOD HasActivePeerConnection(uint32_t innerWindowID, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_IPEERCONNECTIONMANAGER(_to) \
  NS_IMETHOD HasActivePeerConnection(uint32_t innerWindowID, bool *_retval) { return _to HasActivePeerConnection(innerWindowID, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_IPEERCONNECTIONMANAGER(_to) \
  NS_IMETHOD HasActivePeerConnection(uint32_t innerWindowID, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasActivePeerConnection(innerWindowID, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public IPeerConnectionManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IPEERCONNECTIONMANAGER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, IPeerConnectionManager)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* boolean hasActivePeerConnection (in unsigned long innerWindowID); */
NS_IMETHODIMP _MYCLASS_::HasActivePeerConnection(uint32_t innerWindowID, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define IPEERCONNECTION_MANAGER_CONTRACTID "@mozilla.org/dom/peerconnectionmanager;1"

/* starting interface:    IPeerConnectionObserver */
#define IPEERCONNECTIONOBSERVER_IID_STR "e61821ba-7772-4973-b583-1715e4bbaeed"

#define IPEERCONNECTIONOBSERVER_IID \
  {0xe61821ba, 0x7772, 0x4973, \
    { 0xb5, 0x83, 0x17, 0x15, 0xe4, 0xbb, 0xae, 0xed }}

class NS_NO_VTABLE IPeerConnectionObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IPEERCONNECTIONOBSERVER_IID)

  enum {
    kReadyState = 1,
    kIceState = 2,
    kSdpState = 3,
    kSipccState = 4
  };

  /* void onCreateOfferSuccess (in string offer); */
  NS_IMETHOD OnCreateOfferSuccess(const char * offer) = 0;

  /* void onCreateOfferError (in unsigned long code); */
  NS_IMETHOD OnCreateOfferError(uint32_t code) = 0;

  /* void onCreateAnswerSuccess (in string answer); */
  NS_IMETHOD OnCreateAnswerSuccess(const char * answer) = 0;

  /* void onCreateAnswerError (in unsigned long code); */
  NS_IMETHOD OnCreateAnswerError(uint32_t code) = 0;

  /* void onSetLocalDescriptionSuccess (in unsigned long code); */
  NS_IMETHOD OnSetLocalDescriptionSuccess(uint32_t code) = 0;

  /* void onSetRemoteDescriptionSuccess (in unsigned long code); */
  NS_IMETHOD OnSetRemoteDescriptionSuccess(uint32_t code) = 0;

  /* void onSetLocalDescriptionError (in unsigned long code); */
  NS_IMETHOD OnSetLocalDescriptionError(uint32_t code) = 0;

  /* void onSetRemoteDescriptionError (in unsigned long code); */
  NS_IMETHOD OnSetRemoteDescriptionError(uint32_t code) = 0;

  /* void notifyDataChannel (in nsIDOMDataChannel channel); */
  NS_IMETHOD NotifyDataChannel(nsIDOMDataChannel *channel) = 0;

  /* void notifyConnection (); */
  NS_IMETHOD NotifyConnection(void) = 0;

  /* void notifyClosedConnection (); */
  NS_IMETHOD NotifyClosedConnection(void) = 0;

  /* void onStateChange (in unsigned long state); */
  NS_IMETHOD OnStateChange(uint32_t state) = 0;

  /* void onAddStream (in nsIDOMMediaStream stream, in string type); */
  NS_IMETHOD OnAddStream(nsIDOMMediaStream *stream, const char * type) = 0;

  /* void onRemoveStream (); */
  NS_IMETHOD OnRemoveStream(void) = 0;

  /* void onAddTrack (); */
  NS_IMETHOD OnAddTrack(void) = 0;

  /* void onRemoveTrack (); */
  NS_IMETHOD OnRemoveTrack(void) = 0;

  /* void foundIceCandidate (in string candidate); */
  NS_IMETHOD FoundIceCandidate(const char * candidate) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(IPeerConnectionObserver, IPEERCONNECTIONOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_IPEERCONNECTIONOBSERVER \
  NS_IMETHOD OnCreateOfferSuccess(const char * offer); \
  NS_IMETHOD OnCreateOfferError(uint32_t code); \
  NS_IMETHOD OnCreateAnswerSuccess(const char * answer); \
  NS_IMETHOD OnCreateAnswerError(uint32_t code); \
  NS_IMETHOD OnSetLocalDescriptionSuccess(uint32_t code); \
  NS_IMETHOD OnSetRemoteDescriptionSuccess(uint32_t code); \
  NS_IMETHOD OnSetLocalDescriptionError(uint32_t code); \
  NS_IMETHOD OnSetRemoteDescriptionError(uint32_t code); \
  NS_IMETHOD NotifyDataChannel(nsIDOMDataChannel *channel); \
  NS_IMETHOD NotifyConnection(void); \
  NS_IMETHOD NotifyClosedConnection(void); \
  NS_IMETHOD OnStateChange(uint32_t state); \
  NS_IMETHOD OnAddStream(nsIDOMMediaStream *stream, const char * type); \
  NS_IMETHOD OnRemoveStream(void); \
  NS_IMETHOD OnAddTrack(void); \
  NS_IMETHOD OnRemoveTrack(void); \
  NS_IMETHOD FoundIceCandidate(const char * candidate); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_IPEERCONNECTIONOBSERVER(_to) \
  NS_IMETHOD OnCreateOfferSuccess(const char * offer) { return _to OnCreateOfferSuccess(offer); } \
  NS_IMETHOD OnCreateOfferError(uint32_t code) { return _to OnCreateOfferError(code); } \
  NS_IMETHOD OnCreateAnswerSuccess(const char * answer) { return _to OnCreateAnswerSuccess(answer); } \
  NS_IMETHOD OnCreateAnswerError(uint32_t code) { return _to OnCreateAnswerError(code); } \
  NS_IMETHOD OnSetLocalDescriptionSuccess(uint32_t code) { return _to OnSetLocalDescriptionSuccess(code); } \
  NS_IMETHOD OnSetRemoteDescriptionSuccess(uint32_t code) { return _to OnSetRemoteDescriptionSuccess(code); } \
  NS_IMETHOD OnSetLocalDescriptionError(uint32_t code) { return _to OnSetLocalDescriptionError(code); } \
  NS_IMETHOD OnSetRemoteDescriptionError(uint32_t code) { return _to OnSetRemoteDescriptionError(code); } \
  NS_IMETHOD NotifyDataChannel(nsIDOMDataChannel *channel) { return _to NotifyDataChannel(channel); } \
  NS_IMETHOD NotifyConnection(void) { return _to NotifyConnection(); } \
  NS_IMETHOD NotifyClosedConnection(void) { return _to NotifyClosedConnection(); } \
  NS_IMETHOD OnStateChange(uint32_t state) { return _to OnStateChange(state); } \
  NS_IMETHOD OnAddStream(nsIDOMMediaStream *stream, const char * type) { return _to OnAddStream(stream, type); } \
  NS_IMETHOD OnRemoveStream(void) { return _to OnRemoveStream(); } \
  NS_IMETHOD OnAddTrack(void) { return _to OnAddTrack(); } \
  NS_IMETHOD OnRemoveTrack(void) { return _to OnRemoveTrack(); } \
  NS_IMETHOD FoundIceCandidate(const char * candidate) { return _to FoundIceCandidate(candidate); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_IPEERCONNECTIONOBSERVER(_to) \
  NS_IMETHOD OnCreateOfferSuccess(const char * offer) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnCreateOfferSuccess(offer); } \
  NS_IMETHOD OnCreateOfferError(uint32_t code) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnCreateOfferError(code); } \
  NS_IMETHOD OnCreateAnswerSuccess(const char * answer) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnCreateAnswerSuccess(answer); } \
  NS_IMETHOD OnCreateAnswerError(uint32_t code) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnCreateAnswerError(code); } \
  NS_IMETHOD OnSetLocalDescriptionSuccess(uint32_t code) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnSetLocalDescriptionSuccess(code); } \
  NS_IMETHOD OnSetRemoteDescriptionSuccess(uint32_t code) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnSetRemoteDescriptionSuccess(code); } \
  NS_IMETHOD OnSetLocalDescriptionError(uint32_t code) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnSetLocalDescriptionError(code); } \
  NS_IMETHOD OnSetRemoteDescriptionError(uint32_t code) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnSetRemoteDescriptionError(code); } \
  NS_IMETHOD NotifyDataChannel(nsIDOMDataChannel *channel) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyDataChannel(channel); } \
  NS_IMETHOD NotifyConnection(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyConnection(); } \
  NS_IMETHOD NotifyClosedConnection(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyClosedConnection(); } \
  NS_IMETHOD OnStateChange(uint32_t state) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnStateChange(state); } \
  NS_IMETHOD OnAddStream(nsIDOMMediaStream *stream, const char * type) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnAddStream(stream, type); } \
  NS_IMETHOD OnRemoveStream(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnRemoveStream(); } \
  NS_IMETHOD OnAddTrack(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnAddTrack(); } \
  NS_IMETHOD OnRemoveTrack(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnRemoveTrack(); } \
  NS_IMETHOD FoundIceCandidate(const char * candidate) { return !_to ? NS_ERROR_NULL_POINTER : _to->FoundIceCandidate(candidate); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public IPeerConnectionObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IPEERCONNECTIONOBSERVER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, IPeerConnectionObserver)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void onCreateOfferSuccess (in string offer); */
NS_IMETHODIMP _MYCLASS_::OnCreateOfferSuccess(const char * offer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onCreateOfferError (in unsigned long code); */
NS_IMETHODIMP _MYCLASS_::OnCreateOfferError(uint32_t code)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onCreateAnswerSuccess (in string answer); */
NS_IMETHODIMP _MYCLASS_::OnCreateAnswerSuccess(const char * answer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onCreateAnswerError (in unsigned long code); */
NS_IMETHODIMP _MYCLASS_::OnCreateAnswerError(uint32_t code)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onSetLocalDescriptionSuccess (in unsigned long code); */
NS_IMETHODIMP _MYCLASS_::OnSetLocalDescriptionSuccess(uint32_t code)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onSetRemoteDescriptionSuccess (in unsigned long code); */
NS_IMETHODIMP _MYCLASS_::OnSetRemoteDescriptionSuccess(uint32_t code)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onSetLocalDescriptionError (in unsigned long code); */
NS_IMETHODIMP _MYCLASS_::OnSetLocalDescriptionError(uint32_t code)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onSetRemoteDescriptionError (in unsigned long code); */
NS_IMETHODIMP _MYCLASS_::OnSetRemoteDescriptionError(uint32_t code)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyDataChannel (in nsIDOMDataChannel channel); */
NS_IMETHODIMP _MYCLASS_::NotifyDataChannel(nsIDOMDataChannel *channel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyConnection (); */
NS_IMETHODIMP _MYCLASS_::NotifyConnection()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyClosedConnection (); */
NS_IMETHODIMP _MYCLASS_::NotifyClosedConnection()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onStateChange (in unsigned long state); */
NS_IMETHODIMP _MYCLASS_::OnStateChange(uint32_t state)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onAddStream (in nsIDOMMediaStream stream, in string type); */
NS_IMETHODIMP _MYCLASS_::OnAddStream(nsIDOMMediaStream *stream, const char * type)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onRemoveStream (); */
NS_IMETHODIMP _MYCLASS_::OnRemoveStream()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onAddTrack (); */
NS_IMETHODIMP _MYCLASS_::OnAddTrack()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onRemoveTrack (); */
NS_IMETHODIMP _MYCLASS_::OnRemoveTrack()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void foundIceCandidate (in string candidate); */
NS_IMETHODIMP _MYCLASS_::FoundIceCandidate(const char * candidate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    IPeerConnection */
#define IPEERCONNECTION_IID_STR "c86903c7-0a2e-42b4-903c-1518f03b9ba5"

#define IPEERCONNECTION_IID \
  {0xc86903c7, 0x0a2e, 0x42b4, \
    { 0x90, 0x3c, 0x15, 0x18, 0xf0, 0x3b, 0x9b, 0xa5 }}

class NS_NO_VTABLE IPeerConnection : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IPEERCONNECTION_IID)

  enum {
    kHintAudio = 1U,
    kHintVideo = 2U,
    kActionNone = -1,
    kActionOffer = 0,
    kActionAnswer = 1,
    kActionPRAnswer = 2,
    kIceGathering = 0,
    kIceWaiting = 1,
    kIceChecking = 2,
    kIceConnected = 3,
    kIceFailed = 4,
    kDataChannelReliable = 0U,
    kDataChannelPartialReliableRexmit = 1U,
    kDataChannelPartialReliableTimed = 2U
  };

  /* void initialize (in IPeerConnectionObserver observer, in nsIDOMWindow window, [optional] in nsIThread thread); */
  NS_IMETHOD Initialize(IPeerConnectionObserver *observer, nsIDOMWindow *window, nsIThread *thread) = 0;

  /* [implicit_jscontext] void createOffer (in jsval constraints); */
  NS_IMETHOD CreateOffer(const JS::Value & constraints, JSContext* cx) = 0;

  /* [implicit_jscontext] void createAnswer (in jsval constraints); */
  NS_IMETHOD CreateAnswer(const JS::Value & constraints, JSContext* cx) = 0;

  /* void setLocalDescription (in long action, in string sdp); */
  NS_IMETHOD SetLocalDescription(int32_t action, const char * sdp) = 0;

  /* void setRemoteDescription (in long action, in string sdp); */
  NS_IMETHOD SetRemoteDescription(int32_t action, const char * sdp) = 0;

  /* void addStream (in nsIDOMMediaStream stream); */
  NS_IMETHOD AddStream(nsIDOMMediaStream *stream) = 0;

  /* void removeStream (in nsIDOMMediaStream stream); */
  NS_IMETHOD RemoveStream(nsIDOMMediaStream *stream) = 0;

  /* void closeStreams (); */
  NS_IMETHOD CloseStreams(void) = 0;

  /* [implicit_jscontext] readonly attribute jsval localStreams; */
  NS_IMETHOD GetLocalStreams(JSContext* cx, JS::Value *aLocalStreams) = 0;

  /* [implicit_jscontext] readonly attribute jsval remoteStreams; */
  NS_IMETHOD GetRemoteStreams(JSContext* cx, JS::Value *aRemoteStreams) = 0;

  /* void addIceCandidate (in string candidate, in string mid, in unsigned short level); */
  NS_IMETHOD AddIceCandidate(const char * candidate, const char * mid, uint16_t level) = 0;

  /* void close (in bool isSynchronous); */
  NS_IMETHOD Close(bool isSynchronous) = 0;

  /* readonly attribute string localDescription; */
  NS_IMETHOD GetLocalDescription(char * *aLocalDescription) = 0;

  /* readonly attribute string remoteDescription; */
  NS_IMETHOD GetRemoteDescription(char * *aRemoteDescription) = 0;

  /* readonly attribute unsigned long iceState; */
  NS_IMETHOD GetIceState(uint32_t *aIceState) = 0;

  /* readonly attribute unsigned long readyState; */
  NS_IMETHOD GetReadyState(uint32_t *aReadyState) = 0;

  /* readonly attribute unsigned long sipccState; */
  NS_IMETHOD GetSipccState(uint32_t *aSipccState) = 0;

  /* nsIDOMDataChannel createDataChannel (in ACString label, in unsigned short type, in boolean outOfOrderAllowed, in unsigned short maxTime, in unsigned short maxNum); */
  NS_IMETHOD CreateDataChannel(const nsACString & label, uint16_t type, bool outOfOrderAllowed, uint16_t maxTime, uint16_t maxNum, nsIDOMDataChannel * *_retval) = 0;

  /* void connectDataConnection (in unsigned short localport, in unsigned short remoteport, in unsigned short numstreams); */
  NS_IMETHOD ConnectDataConnection(uint16_t localport, uint16_t remoteport, uint16_t numstreams) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(IPeerConnection, IPEERCONNECTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_IPEERCONNECTION \
  NS_IMETHOD Initialize(IPeerConnectionObserver *observer, nsIDOMWindow *window, nsIThread *thread); \
  NS_IMETHOD CreateOffer(const JS::Value & constraints, JSContext* cx); \
  NS_IMETHOD CreateAnswer(const JS::Value & constraints, JSContext* cx); \
  NS_IMETHOD SetLocalDescription(int32_t action, const char * sdp); \
  NS_IMETHOD SetRemoteDescription(int32_t action, const char * sdp); \
  NS_IMETHOD AddStream(nsIDOMMediaStream *stream); \
  NS_IMETHOD RemoveStream(nsIDOMMediaStream *stream); \
  NS_IMETHOD CloseStreams(void); \
  NS_IMETHOD GetLocalStreams(JSContext* cx, JS::Value *aLocalStreams); \
  NS_IMETHOD GetRemoteStreams(JSContext* cx, JS::Value *aRemoteStreams); \
  NS_IMETHOD AddIceCandidate(const char * candidate, const char * mid, uint16_t level); \
  NS_IMETHOD Close(bool isSynchronous); \
  NS_IMETHOD GetLocalDescription(char * *aLocalDescription); \
  NS_IMETHOD GetRemoteDescription(char * *aRemoteDescription); \
  NS_IMETHOD GetIceState(uint32_t *aIceState); \
  NS_IMETHOD GetReadyState(uint32_t *aReadyState); \
  NS_IMETHOD GetSipccState(uint32_t *aSipccState); \
  NS_IMETHOD CreateDataChannel(const nsACString & label, uint16_t type, bool outOfOrderAllowed, uint16_t maxTime, uint16_t maxNum, nsIDOMDataChannel * *_retval); \
  NS_IMETHOD ConnectDataConnection(uint16_t localport, uint16_t remoteport, uint16_t numstreams); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_IPEERCONNECTION(_to) \
  NS_IMETHOD Initialize(IPeerConnectionObserver *observer, nsIDOMWindow *window, nsIThread *thread) { return _to Initialize(observer, window, thread); } \
  NS_IMETHOD CreateOffer(const JS::Value & constraints, JSContext* cx) { return _to CreateOffer(constraints, cx); } \
  NS_IMETHOD CreateAnswer(const JS::Value & constraints, JSContext* cx) { return _to CreateAnswer(constraints, cx); } \
  NS_IMETHOD SetLocalDescription(int32_t action, const char * sdp) { return _to SetLocalDescription(action, sdp); } \
  NS_IMETHOD SetRemoteDescription(int32_t action, const char * sdp) { return _to SetRemoteDescription(action, sdp); } \
  NS_IMETHOD AddStream(nsIDOMMediaStream *stream) { return _to AddStream(stream); } \
  NS_IMETHOD RemoveStream(nsIDOMMediaStream *stream) { return _to RemoveStream(stream); } \
  NS_IMETHOD CloseStreams(void) { return _to CloseStreams(); } \
  NS_IMETHOD GetLocalStreams(JSContext* cx, JS::Value *aLocalStreams) { return _to GetLocalStreams(cx, aLocalStreams); } \
  NS_IMETHOD GetRemoteStreams(JSContext* cx, JS::Value *aRemoteStreams) { return _to GetRemoteStreams(cx, aRemoteStreams); } \
  NS_IMETHOD AddIceCandidate(const char * candidate, const char * mid, uint16_t level) { return _to AddIceCandidate(candidate, mid, level); } \
  NS_IMETHOD Close(bool isSynchronous) { return _to Close(isSynchronous); } \
  NS_IMETHOD GetLocalDescription(char * *aLocalDescription) { return _to GetLocalDescription(aLocalDescription); } \
  NS_IMETHOD GetRemoteDescription(char * *aRemoteDescription) { return _to GetRemoteDescription(aRemoteDescription); } \
  NS_IMETHOD GetIceState(uint32_t *aIceState) { return _to GetIceState(aIceState); } \
  NS_IMETHOD GetReadyState(uint32_t *aReadyState) { return _to GetReadyState(aReadyState); } \
  NS_IMETHOD GetSipccState(uint32_t *aSipccState) { return _to GetSipccState(aSipccState); } \
  NS_IMETHOD CreateDataChannel(const nsACString & label, uint16_t type, bool outOfOrderAllowed, uint16_t maxTime, uint16_t maxNum, nsIDOMDataChannel * *_retval) { return _to CreateDataChannel(label, type, outOfOrderAllowed, maxTime, maxNum, _retval); } \
  NS_IMETHOD ConnectDataConnection(uint16_t localport, uint16_t remoteport, uint16_t numstreams) { return _to ConnectDataConnection(localport, remoteport, numstreams); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_IPEERCONNECTION(_to) \
  NS_IMETHOD Initialize(IPeerConnectionObserver *observer, nsIDOMWindow *window, nsIThread *thread) { return !_to ? NS_ERROR_NULL_POINTER : _to->Initialize(observer, window, thread); } \
  NS_IMETHOD CreateOffer(const JS::Value & constraints, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateOffer(constraints, cx); } \
  NS_IMETHOD CreateAnswer(const JS::Value & constraints, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateAnswer(constraints, cx); } \
  NS_IMETHOD SetLocalDescription(int32_t action, const char * sdp) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLocalDescription(action, sdp); } \
  NS_IMETHOD SetRemoteDescription(int32_t action, const char * sdp) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRemoteDescription(action, sdp); } \
  NS_IMETHOD AddStream(nsIDOMMediaStream *stream) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddStream(stream); } \
  NS_IMETHOD RemoveStream(nsIDOMMediaStream *stream) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveStream(stream); } \
  NS_IMETHOD CloseStreams(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CloseStreams(); } \
  NS_IMETHOD GetLocalStreams(JSContext* cx, JS::Value *aLocalStreams) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocalStreams(cx, aLocalStreams); } \
  NS_IMETHOD GetRemoteStreams(JSContext* cx, JS::Value *aRemoteStreams) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRemoteStreams(cx, aRemoteStreams); } \
  NS_IMETHOD AddIceCandidate(const char * candidate, const char * mid, uint16_t level) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddIceCandidate(candidate, mid, level); } \
  NS_IMETHOD Close(bool isSynchronous) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(isSynchronous); } \
  NS_IMETHOD GetLocalDescription(char * *aLocalDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocalDescription(aLocalDescription); } \
  NS_IMETHOD GetRemoteDescription(char * *aRemoteDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRemoteDescription(aRemoteDescription); } \
  NS_IMETHOD GetIceState(uint32_t *aIceState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIceState(aIceState); } \
  NS_IMETHOD GetReadyState(uint32_t *aReadyState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReadyState(aReadyState); } \
  NS_IMETHOD GetSipccState(uint32_t *aSipccState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSipccState(aSipccState); } \
  NS_IMETHOD CreateDataChannel(const nsACString & label, uint16_t type, bool outOfOrderAllowed, uint16_t maxTime, uint16_t maxNum, nsIDOMDataChannel * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateDataChannel(label, type, outOfOrderAllowed, maxTime, maxNum, _retval); } \
  NS_IMETHOD ConnectDataConnection(uint16_t localport, uint16_t remoteport, uint16_t numstreams) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConnectDataConnection(localport, remoteport, numstreams); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public IPeerConnection
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IPEERCONNECTION

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, IPeerConnection)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void initialize (in IPeerConnectionObserver observer, in nsIDOMWindow window, [optional] in nsIThread thread); */
NS_IMETHODIMP _MYCLASS_::Initialize(IPeerConnectionObserver *observer, nsIDOMWindow *window, nsIThread *thread)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void createOffer (in jsval constraints); */
NS_IMETHODIMP _MYCLASS_::CreateOffer(const JS::Value & constraints, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void createAnswer (in jsval constraints); */
NS_IMETHODIMP _MYCLASS_::CreateAnswer(const JS::Value & constraints, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setLocalDescription (in long action, in string sdp); */
NS_IMETHODIMP _MYCLASS_::SetLocalDescription(int32_t action, const char * sdp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setRemoteDescription (in long action, in string sdp); */
NS_IMETHODIMP _MYCLASS_::SetRemoteDescription(int32_t action, const char * sdp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addStream (in nsIDOMMediaStream stream); */
NS_IMETHODIMP _MYCLASS_::AddStream(nsIDOMMediaStream *stream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeStream (in nsIDOMMediaStream stream); */
NS_IMETHODIMP _MYCLASS_::RemoveStream(nsIDOMMediaStream *stream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void closeStreams (); */
NS_IMETHODIMP _MYCLASS_::CloseStreams()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval localStreams; */
NS_IMETHODIMP _MYCLASS_::GetLocalStreams(JSContext* cx, JS::Value *aLocalStreams)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval remoteStreams; */
NS_IMETHODIMP _MYCLASS_::GetRemoteStreams(JSContext* cx, JS::Value *aRemoteStreams)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addIceCandidate (in string candidate, in string mid, in unsigned short level); */
NS_IMETHODIMP _MYCLASS_::AddIceCandidate(const char * candidate, const char * mid, uint16_t level)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (in bool isSynchronous); */
NS_IMETHODIMP _MYCLASS_::Close(bool isSynchronous)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string localDescription; */
NS_IMETHODIMP _MYCLASS_::GetLocalDescription(char * *aLocalDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string remoteDescription; */
NS_IMETHODIMP _MYCLASS_::GetRemoteDescription(char * *aRemoteDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long iceState; */
NS_IMETHODIMP _MYCLASS_::GetIceState(uint32_t *aIceState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long readyState; */
NS_IMETHODIMP _MYCLASS_::GetReadyState(uint32_t *aReadyState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long sipccState; */
NS_IMETHODIMP _MYCLASS_::GetSipccState(uint32_t *aSipccState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDataChannel createDataChannel (in ACString label, in unsigned short type, in boolean outOfOrderAllowed, in unsigned short maxTime, in unsigned short maxNum); */
NS_IMETHODIMP _MYCLASS_::CreateDataChannel(const nsACString & label, uint16_t type, bool outOfOrderAllowed, uint16_t maxTime, uint16_t maxNum, nsIDOMDataChannel * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void connectDataConnection (in unsigned short localport, in unsigned short remoteport, in unsigned short numstreams); */
NS_IMETHODIMP _MYCLASS_::ConnectDataConnection(uint16_t localport, uint16_t remoteport, uint16_t numstreams)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_IPeerConnection_h__ */
