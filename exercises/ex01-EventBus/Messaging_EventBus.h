//---------------------------------------------------------------------------

#ifndef Messaging_EventBusH
#define Messaging_EventBusH
//---------------------------------------------------------------------------
#include <vector>
#include <System.hpp>
#include <System.Classes.hpp>
//---------------------------------------------------------------------------

class TEvenMessage {
public:
	int TagInt;
	String TagString;
	bool TagBoolean;
};

class TSubscriber : public IUnknown {
public:
	virtual void OnEvent (int MessageID, TEvenMessage *message) = 0;
};

typedef void (__closure *TEventPostMethod)(int MessageID, TEvenMessage* em);

enum TMessageKind {mkSubscriber, mkMethod};

struct RegistrationInfo {
	int messageID;
	TMessageKind kind;
	TSubscriber* subscriber;
	TEventPostMethod method;
};

class TEventBus : public TComponent
{
private:
	std::vector<RegistrationInfo> vSubscribers;
	int LocateSubscriber (int MessageId, TSubscriber* Subscriber);
	int LocateMethod (int MessageId, TEventPostMethod Method);
public:
	__fastcall TEventBus(TComponent* Owner) : TComponent(Owner) {};
	void RegisterSubscriber (int MessageId, TSubscriber* Subscriber);
	void RegisterMethod (int MessageId, TEventPostMethod Method);
	void UnregisterSubscriber (int MessageId, TSubscriber* Subscriber);
	void UnregisterMethod (int MessageId, TEventPostMethod Method);
	void PostMessage (int MessageId, TEvenMessage* mess);
};

TEventBus* GetDefaultEventBus();

#endif
