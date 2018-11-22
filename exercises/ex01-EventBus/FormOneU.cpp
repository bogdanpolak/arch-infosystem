// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormOneU.h"
#include "EventBus_Consts.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
	GetDefaultEventBus()->RegisterSubscriber(EB_BOARD_StartScroll, this);
}

// ---------------------------------------------------------------------------
__fastcall TForm1::~TForm1(void) {
	GetDefaultEventBus()->UnregisterSubscriber(EB_BOARD_StartScroll, this);
}

// ---------------------------------------------------------------------------
void TForm1::OnEvent(int MessageID, TEventMessage *message) {
	this->ListBox1->Items->Add(message->TagString);
}
// ---------------------------------------------------------------------------
