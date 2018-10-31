//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fm_browser_dlg.h"
#include "dm_database_module.h"
#include "fm_person_dlg.h"
#include "user_info.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBrowserDlg *BrowserDlg;
//---------------------------------------------------------------------------

__fastcall TBrowserDlg::TBrowserDlg(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------

int __fastcall TBrowserDlg::getCurrentClientID()
{
   int client_id = -1;

   if(!DataSource1->DataSet->IsEmpty())
   {
      client_id = DataSource1->DataSet->FieldByName("ID_OSOBY")->AsInteger;
   }

   return client_id;
}
//------------------------------------------------------------------------------

bool __fastcall TBrowserDlg::isServiced()
{
   bool serviced = true;

   String client_kind(DataSource1->DataSet->FieldByName("RODZAJ_OSB")->AsString);

   if(client_kind != "F")
   {
      serviced = false;

      ShowMessage(_T("Nieobs³ugiwany rodzaj klienta: '") + client_kind + _T("'"));
   }

   return serviced;
}
//------------------------------------------------------------------------------

void __fastcall TBrowserDlg::refreshData(int client_id)
{
   FDQuery1->DisableControls();

   FDQuery1->Refresh();

   if(client_id > 0)
   {
      FDQuery1->Locate("ID_OSOBY", client_id, TLocateOptions());
   }

   FDQuery1->EnableControls();
}
//------------------------------------------------------------------------------

void __fastcall TBrowserDlg::FormShow(TObject *Sender)
{
   FDQuery1->Open();

   DBGrid1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TBrowserDlg::FormCloseQuery(TObject *Sender, bool &CanClose)
{
   FDQuery1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TBrowserDlg::btInfoClick(TObject *Sender)
{
   if(!DatabaseModule->GetUser().checkRight(klienci::UserInfo::uacView))
   {
      ShowMessage(_T("Brak uprawnienia do podgl¹du danych klientów."));

      return;
   }

   int client_id = getCurrentClientID();

   if(client_id > 0)
   {
      if(isServiced())
      {
         PersonDlg->Info(client_id);
      }
   }
}
//---------------------------------------------------------------------------

void __fastcall TBrowserDlg::btAppendClick(TObject *Sender)
{
   if(!DatabaseModule->GetUser().checkRight(klienci::UserInfo::uacAdd))
   {
      ShowMessage(_T("Brak uprawnienia do dodawania klientów."));

      return;
   }

   int client_id;

   client_id = PersonDlg->Append();

   if(client_id > 0)
   {
      refreshData(client_id);
   }
}
//---------------------------------------------------------------------------

void __fastcall TBrowserDlg::btEditClick(TObject *Sender)
{
   if(!DatabaseModule->GetUser().checkRight(klienci::UserInfo::uacEdit))
   {
      ShowMessage(_T("Brak uprawnienia do edycji danych klientów."));

      return;
   }

   int client_id = getCurrentClientID();

   if(client_id > 0)
   {
      if(isServiced())
      {
         if(PersonDlg->Edit(client_id))
         {
            refreshData(client_id);
         }
      }
   }
}
//---------------------------------------------------------------------------

void __fastcall TBrowserDlg::btEraseClick(TObject *Sender)
{
   if(!DatabaseModule->GetUser().checkRight(klienci::UserInfo::uacErase))
   {
      ShowMessage(_T("Brak uprawnienia do usuwanie klientów."));

      return;
   }

   int client_id = getCurrentClientID();

   if(client_id > 0)
   {
      if(isServiced())
      {
         if(PersonDlg->Erase(client_id))
         {
            FDQuery1->DisableControls();

            FDQuery1->Next();

            if(FDQuery1->Eof)
            {
               FDQuery1->Prior();
            }

            client_id = getCurrentClientID();

            refreshData(client_id);

            FDQuery1->EnableControls();
         }
      }
   }
}
//---------------------------------------------------------------------------

