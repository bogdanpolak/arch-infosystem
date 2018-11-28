// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fm_login_dlg.h"
#include "dm_database_module.h"
#include "fm_main_form.h"
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

UnicodeString __fastcall TLoginDlg::GetUser() {
	return edUser->Text;
}
// ------------------------------------------------------------------------------

bool __fastcall TLoginDlg::Login() {
	ShowModal();

	return ModalResult == mrOk;
}
// ------------------------------------------------------------------------------
void __fastcall TLoginDlg::FormShow(TObject *Sender)
{
  bb1->Visible = MainForm->inDeveloperMode();

/* Wladek
	#if defined _DEBUG
		bb1->Visible = true;
	#else
		bb1->Visible = false;
	#endif
*/
}
//---------------------------------------------------------------------------

void __fastcall TLoginDlg::bb1Click(TObject *Sender)
{
	edUser->Text = L"admin";
	edPassw->Text = L"admin";
    btLogin->SetFocus();
}
//---------------------------------------------------------------------------

