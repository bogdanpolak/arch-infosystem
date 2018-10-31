//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fm_login_dlg.h"
#include "dm_database_module.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------

__fastcall TLoginDlg::TLoginDlg(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TLoginDlg::btLoginClick(TObject *Sender)
{
   if(DatabaseModule->Login(edUser->Text, edPassw->Text))
   {
      ModalResult = mrOk;
   }
   else
   {
      ShowMessage(_T("Nieznany operator lub b³êdne has³o."));

      edPassw->SetFocus();
      edPassw->SelectAll();
   }
}
//---------------------------------------------------------------------------

UnicodeString __fastcall TLoginDlg::GetUser()
{
   return edUser->Text;
}
//------------------------------------------------------------------------------

bool __fastcall TLoginDlg::Login()
{
   ShowModal();

   return ModalResult == mrOk;
}
//------------------------------------------------------------------------------

