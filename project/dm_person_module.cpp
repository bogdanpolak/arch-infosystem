// ---------------------------------------------------------------------------

#pragma hdrstop

#include "dm_person_module.h"
#include "dm_database_module.h"
#include "user_info.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma resource "*.dfm"
TPersonModule *PersonModule;
// ---------------------------------------------------------------------------

const _TCHAR* const cc_PersonQuMainUpdOrIns = _T("update or insert into bo_main(id_osoby, rodzaj_osb, nazwa, nip, kod_kraju, regon, email, telefon, rb_numer, rej_data, rej_oper, mod_data, mod_oper)\
 values(:ID_OSOBY, 'F', :NAZWA, :NIP, :KOD_KRAJU, :REGON, :EMAIL, :TELEFON, :RB_NUMER, :REJ_DATA, :REJ_OPER, :MOD_DATA, :MOD_OPER)\
 matching(id_osoby)");

const _TCHAR* const cc_PersonQuMainDelete =
	_T("delete from bo_main where id_osoby = :ID_OSOBY");

const _TCHAR* const cc_PersonQuDetailUpdOrIns = _T("update or insert into bo_fiz(id_osoby, imie, imie_drugie, nazwisko, imie_ojca, imie_matki, pesel, typ_dok_toz, nr_dok_toz, data_ur, miejsce_ur)\
 values(:ID_OSOBY, :IMIE, :IMIE_DRUGIE, :NAZWISKO, :IMIE_OJCA, :IMIE_MATKI, :PESEL, :TYP_DOK_TOZ, :NR_DOK_TOZ, :DATA_UR, :MIEJSCE_UR)\
 matching(id_osoby)");

__fastcall TPersonModule::TPersonModule(TComponent* Owner)
	: TDataModule(Owner), m_updateError(), m_personID(-1) {
}
// ---------------------------------------------------------------------------

void __fastcall TPersonModule::cdsPersonAfterInsert(TDataSet *DataSet) {
	DataSet->FieldByName("ID_OSOBY")->AsInteger = -1;
}
// ---------------------------------------------------------------------------

void __fastcall TPersonModule::cdsAddressAfterInsert(TDataSet *DataSet) {
	DataSet->Tag = DataSet->Tag - 1;

	DataSet->FieldByName("ID_ADRESU")->AsInteger = DataSet->Tag;
	DataSet->FieldByName("TYP_ADRESU")->AsString = "M";
	DataSet->FieldByName("REJ_DATA")->AsDateTime = Now();
	DataSet->FieldByName("REJ_OPER")->AsInteger =
		DatabaseModule->GetUser().Ident;
}
// ---------------------------------------------------------------------------

void __fastcall TPersonModule::cdsAddressBeforePost(TDataSet *DataSet) {
	DataSet->FieldByName("MOD_DATA")->AsDateTime = Now();
	DataSet->FieldByName("MOD_OPER")->AsInteger =
		DatabaseModule->GetUser().Ident;
}
// ---------------------------------------------------------------------------

void __fastcall TPersonModule::dspPersonBeforeApplyUpdates(TObject *Sender,
	OleVariant &OwnerData) {
	m_updateError = "";

	if (!cdsPerson->IsEmpty()) {
		// je¿eli osoba nie zosta³a usuniêta, to przed zapisaniem zmian w bazie musz¹ zostaæ
		// zaktualizwane wartoœci czêœci pól; w przypadku cdsPerson zawsze jest tylko jeden
		// rekord, wiêc zmiany przeprowadzane s¹ dla bie¿¹cego rekordu

		if (cdsPerson->State == dsBrowse) {
			cdsPerson->Edit();
		}

		int person_id = m_personID;

		if (person_id == -1) {
			spPersonID->ExecProc();

			person_id = spPersonID->ParamByName("ID_OSOBY")->AsInteger;

			cdsPerson->FieldByName("ID_OSOBY")->AsInteger = person_id;
			cdsPerson->FieldByName("REJ_DATA")->AsDateTime = Now();
			cdsPerson->FieldByName("REJ_OPER")->AsInteger =
				DatabaseModule->GetUser().Ident;
		}
		else {
			cdsPerson->FieldByName("MOD_DATA")->AsDateTime = Now();
			cdsPerson->FieldByName("MOD_OPER")->AsInteger =
				DatabaseModule->GetUser().Ident;
		}

		cdsPerson->FieldByName("NAZWA")->AsString =
			cdsPerson->FieldByName("NAZWISKO")->AsString + " " +
			cdsPerson->FieldByName("IMIE")->AsString;

		cdsPerson->Post();
	}
}
// ---------------------------------------------------------------------------

void __fastcall TPersonModule::dspPersonUpdateError(TObject *Sender,
	TCustomClientDataSet *DataSet, EUpdateError *E, TUpdateKind UpdateKind,
	TResolverResponse &Response) {
	m_updateError = E->Message;
}
// ---------------------------------------------------------------------------

void __fastcall TPersonModule::dspPersonBeforeUpdateRecord(TObject *Sender,
	TDataSet *SourceDS, TCustomClientDataSet *DeltaDS, TUpdateKind UpdateKind,
	bool &Applied) {
	if (SourceDS == quPerson) {
		if (UpdateKind != ukDelete) {
			// aktualizacja dotycz¹ca tabeli BO_MAIN

			quCommand->CommandText->Text = cc_PersonQuMainUpdOrIns;

			quCommand->Prepare();

			for (int ii = 0; ii < quCommand->Params->Count; ++ii) {
				TFDParam* param = quCommand->Params->Items[ii];

				param->AssignFieldValue(cdsPerson->FieldByName(param->Name));
			}

			quCommand->Execute();

			// aktualizacja dotycz¹ca tabeli BO_FIZ

			quCommand->CommandText->Text = cc_PersonQuDetailUpdOrIns;

			quCommand->Prepare();

			for (int ii = 0; ii < quCommand->Params->Count; ++ii) {
				TFDParam* param = quCommand->Params->Items[ii];

				param->AssignFieldValue(cdsPerson->FieldByName(param->Name));
			}

			quCommand->Execute();
		}
		else {
			// usuniêcie osoby - jawnie usuwany jest rekord z tabeli BO_MAIN; rekord z BO_FIZ i
			// adresy z tabeli BO_ADRES zostan¹ usuniête przez motor bazy danych (on delete cascade)

			quCommand->CommandText->Text = cc_PersonQuMainDelete;

			quCommand->Prepare();

			quCommand->ParamByName("ID_OSOBY")->AsInteger = m_personID;

			quCommand->Execute();
		}

		Applied = true;
	}
	else if (SourceDS == quAddress) {
		if (UpdateKind == ukInsert) {
			DeltaDS->Edit();

			spAddressID->ExecProc();

			DeltaDS->FieldByName("ID_ADRESU")->AsInteger =
				spAddressID->ParamByName("ID_ADRESU")->AsInteger;

			DeltaDS->FieldByName("REJ_DATA")->AsDateTime = Now();
			DeltaDS->FieldByName("REJ_OPER")->AsInteger =
				DatabaseModule->GetUser().Ident;

			// zmiana identyfikatora osoby w przypadku nowego klienta nie propaguje siê do jego
			// adresów; poni¿szy kod naprawia ten mankament

			if (DeltaDS->FieldByName("ID_OSOBY")->AsInteger < 0) {
				DeltaDS->FieldByName("ID_OSOBY")->AsInteger =
					cdsPerson->FieldByName("ID_OSOBY")->AsInteger;
			}

			DeltaDS->Post();
		}
	}
}
// ---------------------------------------------------------------------------

int __fastcall TPersonModule::GetPersonID() {
	return m_personID;
}
// ------------------------------------------------------------------------------

bool __fastcall TPersonModule::IsEditing() {
	return cdsPerson->State != dsBrowse;
}
// ------------------------------------------------------------------------------

void __fastcall TPersonModule::Open(int person_id) {
	if (cdsPerson->Active) {
		Close();
	}

	m_personID = (person_id > 0) ? person_id : -1;

	try {
		trPerson->StartTransaction();

		quPerson->ParamByName("ID_OSOBY")->AsInteger = m_personID;

		cdsPerson->Open();

		trPerson->Commit();
	}
	catch (...) {
		trPerson->Rollback();

		throw;
	}
}
// ------------------------------------------------------------------------------

void __fastcall TPersonModule::Append() {
	Open(-1);

	cdsPerson->Append();
}
// ------------------------------------------------------------------------------

void __fastcall TPersonModule::Edit() {
	cdsPerson->Edit();
}
// ------------------------------------------------------------------------------

void __fastcall TPersonModule::Erase() {
	cdsPerson->Delete();
}
// ------------------------------------------------------------------------------

void __fastcall TPersonModule::Post() {
	cdsPerson->Post();
}
// ------------------------------------------------------------------------------

void __fastcall TPersonModule::Cancel() {
	cdsPerson->Cancel();
}
// ------------------------------------------------------------------------------

void __fastcall TPersonModule::Close() {
	cdsPerson->Close();
}
// ------------------------------------------------------------------------------

void __fastcall TPersonModule::ApplyUpdates() {
	try {
		cdsPerson->DisableControls();

		cdsAddress->DisableControls();

		trPerson->StartTransaction();

		cdsPerson->ApplyUpdates(0);

		if (!m_updateError.IsEmpty()) {
			throw Exception(m_updateError);
		}

		trPerson->Commit();

		if (!cdsPerson->IsEmpty()) {
			m_personID = cdsPerson->FieldByName("ID_OSOBY")->AsInteger;
		}

		cdsPerson->EnableControls();

		cdsAddress->EnableControls();
	}
	catch (...) {
		trPerson->Rollback();

		cdsPerson->EnableControls();

		cdsAddress->EnableControls();

		throw;
	}
}
// ------------------------------------------------------------------------------

void __fastcall TPersonModule::CancelUpdates() {
	cdsPerson->CancelUpdates();
}
// ------------------------------------------------------------------------------
