// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fm_property_account_dlg.h"
#include "dm_property_module.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPropertyAccount *PropertyAccount;
// ---------------------------------------------------------------------------

__fastcall TPropertyAccount::TPropertyAccount(TComponent* Owner) : TForm(Owner)
{
  m_propertyModule = new TPropertyModule(this);

  dsKonta->DataSet = m_propertyModule->quKonta;
  dsSkladniki->DataSet = m_propertyModule->quSkladniki;
  dsPodatnicy->DataSet = m_propertyModule->quPodatnicy;
}
// ---------------------------------------------------------------------------
void __fastcall TPropertyAccount::FormShow(TObject *Sender)
{
  m_propertyModule->Open();
}
//---------------------------------------------------------------------------

