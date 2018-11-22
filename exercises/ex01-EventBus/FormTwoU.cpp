// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormTwoU.h"
#include "EventBus_Consts.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

// ---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner) : TForm(Owner) {
	TEventBus* bus = GetDefaultEventBus();
	bus->RegisterSubscriber(EB_BOARD_StartScroll, this);
	bus->RegisterMethod(EB_BOARD_ChangeSpeed, this->EvenBusOnChangeSpeed);
	bus->RegisterMethod(EB_BOARD_ChangeColor, this->EvenBusOnChangeColor);
	bus->RegisterMethod(EB_BOARD_Animate, this->EvenBusOnAnimate);
	bus->RegisterMethod(EB_BOARD_Pause, this->EvenBusOnPause);
}

// ---------------------------------------------------------------------------
__fastcall TForm2::~TForm2(void) {
	TEventBus* bus = GetDefaultEventBus();
	bus->UnregisterSubscriber(EB_BOARD_StartScroll, this);
	bus->UnregisterMethod(EB_BOARD_ChangeSpeed, this->EvenBusOnChangeSpeed);
	bus->UnregisterMethod(EB_BOARD_ChangeColor, this->EvenBusOnChangeColor);
	bus->UnregisterMethod(EB_BOARD_Animate, this->EvenBusOnAnimate);
	bus->UnregisterMethod(EB_BOARD_Pause, this->EvenBusOnPause);
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender) {
	DefualtTimerInterval = tmrAnimate->Interval;
	Label1->Visible = false;
}

// ---------------------------------------------------------------------------
void TForm2::OnEvent(int MessageID, TEventMessage *message) {
	tmrAnimate->Enabled = false;
	Label1->Left = this->ClientWidth - 150;
	Label1->Top = 8;
	Label1->Font->Size = 60;
	Label1->Caption = message->TagString;
	Label1->Visible = true;
	tmrAnimate->Enabled = true;
}

// ---------------------------------------------------------------------------
void TForm2::EvenBusOnChangeSpeed(int MessageID, TEventMessage *message) {
	if (message->TagBoolean)
		tmrAnimate->Interval = DefualtTimerInterval / 2;
	else
		tmrAnimate->Interval = DefualtTimerInterval;
}

// ---------------------------------------------------------------------------
void TForm2::EvenBusOnChangeColor(int MessageID, TEventMessage *message) {
	Label1->Font->Color = (TColor) message->TagInt;
}

// ---------------------------------------------------------------------------
void TForm2::EvenBusOnPause(int MessageID, TEventMessage *message) {
	tmrAnimate->Enabled = false;
}

// ---------------------------------------------------------------------------
void TForm2::EvenBusOnAnimate(int MessageID, TEventMessage *message) {
	tmrAnimate->Enabled = true;
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::tmrAnimateTimer(TObject *Sender) {
	Label1->Left -= 5;
}
// ---------------------------------------------------------------------------
