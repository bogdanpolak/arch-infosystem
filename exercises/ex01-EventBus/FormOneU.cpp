//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormOneU.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TForm1::OnEvent (int MessageID, TEvenMessage *message) {
	this->ListBox1->Items->Add(message->TagString);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	GetDefaultEventBus()->RegisterSubscriber(1,this);
}
//---------------------------------------------------------------------------
