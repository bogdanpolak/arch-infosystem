//---------------------------------------------------------------------------

#pragma hdrstop

#include "Messaging_EventBus.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
int TEventBus::LocateSubscriber (int MessageId, TSubscriber* Subscriber){
	for(unsigned int i = 0; i < vSubscribers.size(); i++) {
		bool isSame = (vSubscribers[i].messageID == MessageId)
			&& (vSubscribers[i].kind == mkSubscriber)
			&& (vSubscribers[i].subscriber == Subscriber);
		if (isSame)
			return i;
	}
    return -1;
}
int TEventBus::LocateMethod (int MessageId, TEventPostMethod Method){
	for(unsigned int i = 0; i < vSubscribers.size(); i++) {
		bool isSame = (vSubscribers[i].messageID == MessageId)
			&& (vSubscribers[i].kind == mkMethod)
			&& (vSubscribers[i].method == Method);
		if (isSame)
			return i;
	}
    return -1;
}
//---------------------------------------------------------------------------
void TEventBus::RegisterSubscriber (int MessageId, TSubscriber* Subscriber) {
	int idx = LocateSubscriber(MessageId, Subscriber);
	if (idx<0) {
		vSubscribers.push_back( RegistrationInfo() );
		RegistrationInfo* regInfo = &vSubscribers.back();
		regInfo->messageID = MessageId;
		regInfo->kind = mkSubscriber;
		regInfo->subscriber = Subscriber;
	}
}
//---------------------------------------------------------------------------
void TEventBus::RegisterMethod (int MessageId, TEventPostMethod Method) {
	int idx = LocateMethod(MessageId, Method);
	if (idx<0) {
		vSubscribers.push_back( RegistrationInfo() );
		RegistrationInfo* regInfo = &vSubscribers.back();
		regInfo->messageID = MessageId;
		regInfo->kind = mkMethod;
		regInfo->method = Method;
	}
}
//---------------------------------------------------------------------------
void TEventBus::UnregisterSubscriber (int MessageId, TSubscriber* Subscriber){
}
//---------------------------------------------------------------------------
void TEventBus::UnregisterMethod (int MessageId, TEventPostMethod Method){
}
//---------------------------------------------------------------------------
void TEventBus::PostMessage (int MessageId, TEvenMessage* mess) {
	for(unsigned int i = 0; i < vSubscribers.size(); i++)
		if (vSubscribers[i].messageID == MessageId) {
			switch (vSubscribers[i].kind) {
			case (mkSubscriber):
				vSubscribers[i].subscriber->OnEvent(MessageId,mess);
				break;
			case (mkMethod):
				vSubscribers[i].method(MessageId,mess);
				break;
			default:
				;
			}
		}

}
//---------------------------------------------------------------------------
TEventBus* GlobalEventBus = 0;
//---------------------------------------------------------------------------
TEventBus* GetDefaultEventBus()
{
	if (!GlobalEventBus) {
		GlobalEventBus = new TEventBus(0);
	}
	return GlobalEventBus;
}

