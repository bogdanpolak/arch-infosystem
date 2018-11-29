// ---------------------------------------------------------------------------

#pragma hdrstop

#include "dm_property_module.h"
#include "dm_database_module.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma resource "*.dfm"
// ---------------------------------------------------------------------------

const char* const cc_PropertyKntQu = "SELECT * FROM PD_KONTA";
const char* const cc_PropertySklQu =
	"SELECT s.* FROM PD_SKLADNIKI s WHERE s.ID_KONTA = :ID_KONTA ";
const char* const cc_PropertyPdtQu =
	"SELECT p.*, m.*  FROM PD_PODATNICY p INNER JOIN BO_MAIN m ON (p.ID_OSOBY=m.ID_OSOBY)WHERE p.ID_KONTA = :ID_KONTA";

__fastcall TPropertyModule::TPropertyModule(TComponent* Owner)
	: TDataModule(Owner) {
	quKonta->SQL->Text = cc_PropertyKntQu;
	quSkladniki->SQL->Text = cc_PropertySklQu;
	quPodatnicy->SQL->Text = cc_PropertyPdtQu;

	quSkladniki->MasterSource = dsKonta;
	quSkladniki->MasterFields = "ID_KONTA";

	quPodatnicy->MasterSource = dsKonta;
	quPodatnicy->MasterFields = "ID_KONTA";
}
// ---------------------------------------------------------------------------

void __fastcall TPropertyModule::Open() {
	quKonta->Active = true;
	quSkladniki->Active = true;
	quPodatnicy->Active = true;
}
