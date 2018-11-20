//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vector>

//---------------------------------------------------------------------------
void TForm1::OnEvent (TEvenMessage *message) {
	this->ListBox1->Items->Add(message->TagString);
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnRegisterClick(TObject *Sender)
{
	Caption = "Registered.";
	btnRegister->Enabled = false;
	btnPost->Enabled = true;
	TEventBus* EBus = GetDefaultEventBus();
	EBus->RegisterSubscriber(1,this);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnPostClick(TObject *Sender)
{
	TEventBus* EBus = GetDefaultEventBus();
	TEvenMessage* AMessage = new TEvenMessage();
	this->Tag = this->Tag + 1;
	AMessage->TagString = L"Komunikat "+IntToStr(this->Tag);
	EBus->PostEvent(1,AMessage);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	btnRegister->Enabled = true;
	btnPost->Enabled = false;
}
//---------------------------------------------------------------------------

