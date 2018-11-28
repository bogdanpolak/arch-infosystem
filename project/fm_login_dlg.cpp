// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fm_login_dlg.h"
#include "dm_database_module.h"
//#include "fm_main_form.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
// ---------------------------------------------------------------------------

__fastcall TLoginDlg::TLoginDlg(TComponent* Owner) : TForm(Owner) {
}
// ---------------------------------------------------------------------------

void __fastcall TLoginDlg::btLoginClick(TObject *Sender) {
	if (DatabaseModule->Login(edUser->Text, edPassw->Text)) {
		ModalResult = mrOk;
	}
	else {
		ShowMessage(_T("Nieznany operator lub b³êdne has³o."));

		edPassw->SetFocus();
		edPassw->SelectAll();
	}
}
// ---------------------------------------------------------------------------

boolean __fastcall TLoginDlg::signInDeveloperMode()
{
	#if defined _DEBUG
		String projFileName = ChangeFileExt(ExtractFileName(Application->ExeName),
		".cbproj");
		if(FileExists("..\\..\\"+projFileName))
		{
			return true;
		}
	#else
		return false;
	#endif
}
// ---------------------------------------------------------------------------

UnicodeString __fastcall TLoginDlg::GetUser() {
	return edUser->Text;
}
// ------------------------------------------------------------------------------

bool __fastcall TLoginDlg::Login() {
	ShowModal();

	return ModalResult == mrOk;
}
// ------------------------------------------------------------------------------
void __fastcall TLoginDlg::FormShow(TObject *Sender){

	if(signInDeveloperMode())
	{
		bbSignIn->Visible = true;
		btLogin->Enabled  = false;
		edUser->Text      = L"admin";
		edPassw->Text     = L"admin";
	}
	else
	{
		bbSignIn->Visible = false;
		btLogin->Enabled  = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TLoginDlg::bbSignInClick(TObject *Sender) {

	btLoginClick(Sender);
}
//---------------------------------------------------------------------------

