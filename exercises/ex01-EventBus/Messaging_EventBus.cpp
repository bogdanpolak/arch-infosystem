// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Messaging_EventBus.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

// ---------------------------------------------------------------------------
int TEventBus::LocateSubscriber(int MessageId, TSubscriber* Subscriber) {
	for (unsigned int i = 0; i < vSubscribers.size(); i++) {
		TRegistrationInfo* info = &vSubscribers[i];
		bool isSame = (info->messageID == MessageId) &&
			(info->kind == mkSubscriber) && (info->subscriber == Subscriber);
		if (isSame)
			return i;
	}
	return -1;
}

int TEventBus::LocateMethod(int MessageId, TEventPostMethod Method) {
	for (unsigned int i = 0; i < vSubscribers.size(); i++) {
		TRegistrationInfo* info = &vSubscribers[i];
		bool isSame = (info->messageID == MessageId) && (info->kind == mkMethod)
			&& (info->method == Method);
		if (isSame)
			return i;
	}
	return -1;
}

// ---------------------------------------------------------------------------
void TEventBus::RegisterSubscriber(int MessageId, TSubscriber* Subscriber) {
	int idx = LocateSubscriber(MessageId, Subscriber);
	if (idx < 0) {
		vSubscribers.push_back(TRegistrationInfo());
		TRegistrationInfo* regInfo = &vSubscribers.back();
		regInfo->messageID = MessageId;
		regInfo->kind = mkSubscriber;
		regInfo->subscriber = Subscriber;
	}
}

// ---------------------------------------------------------------------------
void TEventBus::RegisterMethod(int MessageId, TEventPostMethod Method) {
	int idx = LocateMethod(MessageId, Method);
	if (idx < 0) {
		vSubscribers.push_back(TRegistrationInfo());
		TRegistrationInfo* regInfo = &vSubscribers.back();
		regInfo->messageID = MessageId;
		regInfo->kind = mkMethod;
		regInfo->method = Method;
	}
}

// ---------------------------------------------------------------------------
void TEventBus::UnregisterSubscriber(int MessageId, TSubscriber* Subscriber) {
	int idx = LocateSubscriber(MessageId, Subscriber);
	if (idx >= 0)
		vSubscribers.erase(vSubscribers.begin() + idx);
}

// ---------------------------------------------------------------------------
void TEventBus::UnregisterMethod(int MessageId, TEventPostMethod Method) {
	int idx = LocateMethod(MessageId, Method);
	if (idx >= 0)
		vSubscribers.erase(vSubscribers.begin() + idx);
}

// ---------------------------------------------------------------------------
void TEventBus::PostMessage(int MessageId, TEventMessage* mess) {
	for (unsigned int i = 0; i < vSubscribers.size(); i++)
		if (vSubscribers[i].messageID == MessageId) {
			switch (vSubscribers[i].kind) {
			case (mkSubscriber):
				vSubscribers[i].subscriber->OnEvent(MessageId, mess);
				break;
			case (mkMethod):
				vSubscribers[i].method(MessageId, mess);
				break;
			default: ;
			}
		}

}

// ---------------------------------------------------------------------------
void TEventBus::PostPing(int MessageId) {
	this->PostMessage(MessageId, 0);
}
// ---------------------------------------------------------------------------
TEventBus* GlobalEventBus = 0;

// ---------------------------------------------------------------------------
TEventBus* GetDefaultEventBus() {
	if (!GlobalEventBus) {
		GlobalEventBus = new TEventBus(0);
	}
	return GlobalEventBus;
}
