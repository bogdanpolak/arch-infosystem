//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormOneU.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
	GetDefaultEventBus()->RegisterSubscriber(1,this);
}
//---------------------------------------------------------------------------
__fastcall TForm1::~TForm1(void) {
	GetDefaultEventBus()->UnregisterSubscriber(1,this);
}
//---------------------------------------------------------------------------
void TForm1::OnEvent (int MessageID, TEvenMessage *message) {
	this->ListBox1->Items->Add(message->TagString);
}
//---------------------------------------------------------------------------
