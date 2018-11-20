//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormMainU.h"
#include "Messaging_EventBus.h"
#include "FormOneU.h"
#include "FormTwoU.h"
#include "EventBus_Consts.h"
//---------------------------------------------------------------------------
#include <memory>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::UpdateControlsEnable(bool Registered) {
	btnShowSubscribers->Enabled = !Registered;
	btnPostMessage1->Enabled = Registered;
	Edit1->Enabled = Registered;
	chkFastAnimataion->Enabled = Registered;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::FormCreate(TObject *Sender)
{
	UpdateControlsEnable (false);
	TEdit* edt = new TEdit ((TComponent *)0);
	edt->Left = 0;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::btnShowSubscribersClick(TObject *Sender)
{
	UpdateControlsEnable (true);
	// ---
	TForm1* frm1;
	Application->CreateForm(__classid(TForm1), &frm1);
	frm1->Visible = true;
	frm1->Left = this->Left + this->Width;
	frm1->Top = this->Top;
	frm1->Show();
	// ---
	TForm2* frm2;
	Application->CreateForm(__classid(TForm2), &frm2);
	// TForm2* frm2 = new TForm2(this);
	frm2->Visible = true;
	frm2->Left = frm1->Left + frm1->Width;
	frm2->Top = this->Top;
	frm2->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::btnPostMessage1Click(TObject *Sender)
{
	TEvenMessage* AMessage = new TEvenMessage();
	try
	{
		this->Tag = this->Tag + 1;
		AMessage->TagString = Edit1->Text;
		GetDefaultEventBus()->PostMessage(EB_BOARD_StartScroll,AMessage);
	}
	 __finally
	{
		delete AMessage;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::chkFastAnimataionClick(TObject *Sender)
{
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// TEvenMessage* AMessage = new TEvenMessage();
	// try
	// {
	//     ...
	// }
	//  __finally
	// {
	//     delete AMessage;
	// }
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// #include <memory>
	// std::unique_ptr<TEvenMessage> AMessage(new TEvenMessage);
	// ...
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	std::unique_ptr<TEvenMessage> AMessage(new TEvenMessage);
	AMessage->TagBoolean = chkFastAnimataion->Checked;
	GetDefaultEventBus()->PostMessage(EB_BOARD_ChangeSpeed,AMessage.get());
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::ColorBox1Change(TObject *Sender)
{
	TColor col = ColorBox1->Selected;
	std::unique_ptr<TEvenMessage> AMessage(new TEvenMessage);
	AMessage->TagInt = col;
	GetDefaultEventBus()->PostMessage(EB_BOARD_ChangeColor,AMessage.get());
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::btnExitClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

