// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fm_property_account_dlg.h"
#include "dm_database_module.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPropertyAccount *PropertyAccount;
// ---------------------------------------------------------------------------

__fastcall TPropertyAccount::TPropertyAccount(TComponent* Owner) : TForm(Owner)
{
}
// ---------------------------------------------------------------------------
