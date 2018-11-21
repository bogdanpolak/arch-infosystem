//---------------------------------------------------------------------------

#ifndef Messaging_EventBusH
#define Messaging_EventBusH
//---------------------------------------------------------------------------
#include <vector>
#include <System.hpp>
#include <System.Classes.hpp>
//---------------------------------------------------------------------------

class TEventMessage {
public:
	int TagInt;
	String TagString;
	bool TagBoolean;
};

class TSubscriber : public IUnknown {
public:
	virtual void OnEvent (int MessageID, TEventMessage *message) = 0;
};

typedef void (__closure *TEventPostMethod)(int MessageID, TEventMessage* em);

enum TMessageKind {mkSubscriber, mkMethod};

struct TRegistrationInfo {
	int messageID;
	TMessageKind kind;
	TSubscriber* subscriber;
	TEventPostMethod method;
};

class TEventBus : public TComponent
{
private:
	std::vector<TRegistrationInfo> vSubscribers;
	int LocateSubscriber (int MessageId, TSubscriber* Subscriber);
	int LocateMethod (int MessageId, TEventPostMethod Method);
public:
	__fastcall TEventBus(TComponent* Owner) : TComponent(Owner) {};
	void RegisterSubscriber (int MessageId, TSubscriber* Subscriber);
	void RegisterMethod (int MessageId, TEventPostMethod Method);
	void UnregisterSubscriber (int MessageId, TSubscriber* Subscriber);
	void UnregisterMethod (int MessageId, TEventPostMethod Method);
	void PostMessage (int MessageId, TEventMessage* mess);
	void PostPing (int MessageId);
};

TEventBus* GetDefaultEventBus();

#endif
