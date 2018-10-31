//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fm_seek_client_dlg.h"
#include "dm_database_module.h"
#include "fm_select_client_dlg.h"
#include <System.StrUtils.hpp>
#include <memory>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSeekClientDlg *SeekClientDlg;
//---------------------------------------------------------------------------

const _TCHAR* const cc_SelectIdent =
_T("select * from bo_main m inner join bo_adres a on (a.id_osoby = m.id_osoby) where m.id_osoby = :ID_OSOBY");

const _TCHAR* const cc_SelectName =
_T("select * from bo_main m inner join bo_adres a on (a.id_osoby = m.id_osoby) where upper(m.nazwa) like upper(:NAZWA)");


__fastcall TSeekClientDlg::TSeekClientDlg(TComponent* Owner)
   : TForm(Owner), m_clientID(-1), m_clientKind()
{
}
//---------------------------------------------------------------------------

void __fastcall TSeekClientDlg::FormShow(TObject *Sender)
{
   Edit1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TSeekClientDlg::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
{
   if(Key == '\r')
   {
      Key = 0;

      Button1Click(Sender);
   }
}
//---------------------------------------------------------------------------

void __fastcall TSeekClientDlg::Button1Click(TObject *Sender)
{
   if(Edit1->Text.IsEmpty())
   {
      return;
   }

   int client_id = StrToIntDef(Edit1->Text, -1);

   if(client_id > 0)
   {
      DatabaseModule->SelectData->SQL->Text = cc_SelectIdent;

      DatabaseModule->SelectData->Prepare();

      DatabaseModule->SelectData->ParamByName("ID_OSOBY")->AsInteger = client_id;
   }
   else
   {
      DatabaseModule->SelectData->SQL->Text = cc_SelectName;

      DatabaseModule->SelectData->Prepare();

      DatabaseModule->SelectData->ParamByName("NAZWA")->AsString = Edit1->Text + (EndsText(_T("%"), Edit1->Text) ? _T("") : _T("%"));
   }


   DatabaseModule->SelectData->Open();

   if(!DatabaseModule->SelectData->IsEmpty())
   {
      bool found = false;

      if(DatabaseModule->SelectData->RecordCount == 1)
      {
         found = true;
      }
      else
      {
         std::auto_ptr<TSelectClientDlg> dlg(new TSelectClientDlg(this));

         dlg->DataSource1->DataSet = DatabaseModule->SelectData;

         if(dlg->Select() > 0)
         {
            found = true;
         }
      }

      if(found)
      {
         m_clientID = DatabaseModule->SelectData->FieldByName("ID_OSOBY")->AsInteger;

         m_clientKind = DatabaseModule->SelectData->FieldByName("RODZAJ_OSB")->AsString;

         ModalResult = mrOk;
      }
      else
      {
         ShowMessage(_T("Nie zosta³ wybrany ¿aden klient."));
      }
   }
   else
   {
      String message(_T("Brak klienta o "));

      message += (client_id > 0) ? _T("identyfikatorze ") : _T("nazwie ");
      message += Edit1->Text;

      ShowMessage(message);
   }

   DatabaseModule->SelectData->Close();
}
//---------------------------------------------------------------------------

int __fastcall TSeekClientDlg::GetClientID()
{
   return m_clientID;
}
//------------------------------------------------------------------------------

String __fastcall TSeekClientDlg::GetClientKind()
{
   return m_clientKind;
}
//------------------------------------------------------------------------------

int __fastcall TSeekClientDlg::Display()
{
   m_clientID   = -1;
   m_clientKind = "";

   try
   {
      ShowModal();
   }
   catch(Exception& exc)
   {
      Application->ShowException(&exc);
   }

   return m_clientID;
}
//------------------------------------------------------------------------------

