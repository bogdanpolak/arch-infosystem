// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fm_person_dlg.h"
#include "dm_person_module.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPersonDlg *PersonDlg;
// ---------------------------------------------------------------------------

__fastcall TPersonDlg::TPersonDlg(TComponent* Owner) : TForm(Owner) {
}
// ---------------------------------------------------------------------------

void __fastcall TPersonDlg::FormShow(TObject *Sender) {
	String typ_dok_toz(PersonModule->cdsPerson->FieldByName("TYP_DOK_TOZ")
		->AsString);
   /* TODO 2 : do zrobienia!!! */
	if (typ_dok_toz.IsEmpty()) {
		cbRodzajDok->ItemIndex = -1;
	}
	else {
		switch (typ_dok_toz[1]) {
		case 'D':
			cbRodzajDok->ItemIndex = 0;
			break;

		case 'J':
			cbRodzajDok->ItemIndex = 1;
			break;

		case 'P':
			cbRodzajDok->ItemIndex = 2;
			break;

		default:
			cbRodzajDok->ItemIndex = -1;
			break;
		}
	}

	if (PersonModule->IsEditing()) {
		DBEdit1->SetFocus();
	}
	else {
		btSave->SetFocus();
	}
}
// ---------------------------------------------------------------------------

void __fastcall TPersonDlg::FormCloseQuery(TObject *Sender, bool &CanClose) {
	CanClose = !PersonModule->IsEditing();
}
// ---------------------------------------------------------------------------

void __fastcall TPersonDlg::dsPersonUpdateData(TObject *Sender) {
	switch (cbRodzajDok->ItemIndex) {
	case 0:
		PersonModule->cdsPerson->FieldByName("TYP_DOK_TOZ")->AsString = "D";
		break;

	case 1:
		PersonModule->cdsPerson->FieldByName("TYP_DOK_TOZ")->AsString = "J";
		break;

	case 2:
		PersonModule->cdsPerson->FieldByName("TYP_DOK_TOZ")->AsString = "P";
		break;

	default:
		PersonModule->cdsPerson->FieldByName("TYP_DOK_TOZ")->Clear();
		break;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TPersonDlg::dsAddressDataChange(TObject *Sender, TField *Field)
{
	if (Field == NULL) {
		String typ_adr(PersonModule->cdsAddress->FieldByName("TYP_ADRESU")
			->AsString);

		if (typ_adr.IsEmpty()) {
			cbRodzajAdr->ItemIndex = -1;
		}
		else {
			switch (typ_adr[1]) {
			case 'M':
				cbRodzajAdr->ItemIndex = 0;
				break;

			case 'Z':
				cbRodzajAdr->ItemIndex = 1;
				break;

			case 'S':
				cbRodzajAdr->ItemIndex = 2;
				break;

			case 'I':
				cbRodzajAdr->ItemIndex = 3;
				break;

			default:
				cbRodzajAdr->ItemIndex = -1;
				break;
			}
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TPersonDlg::dsAddressUpdateData(TObject *Sender) {
	switch (cbRodzajAdr->ItemIndex) {
	case 0:
		PersonModule->cdsAddress->FieldByName("TYP_ADRESU")->AsString = "M";
		break;

	case 1:
		PersonModule->cdsAddress->FieldByName("TYP_ADRESU")->AsString = "Z";
		break;

	case 2:
		PersonModule->cdsAddress->FieldByName("TYP_ADRESU")->AsString = "S";
		break;

	case 3:
		PersonModule->cdsAddress->FieldByName("TYP_ADRESU")->AsString = "I";
		break;

	default:
		PersonModule->cdsAddress->FieldByName("TYP_ADRESU")->Clear();
		break;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TPersonDlg::aciCancelExecute(TObject *Sender) {
	if (Application->MessageBox(_T("Czy na pewno anulowaæ wprowadzone zmiany?"),
		_T("Zapisywanie danych klienta"), MB_YESNO) == IDYES) {
		PersonModule->CancelUpdates();

		ModalResult = mrCancel;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TPersonDlg::aciSaveExecute(TObject *Sender) {
	if (Application->MessageBox(_T("Czy zapisaæ wprowadzone zmiany?"),
		_T("Zapisywanie danych klienta"), MB_YESNO) == IDYES) {
		PersonModule->Post();

		PersonModule->ApplyUpdates();

		ModalResult = mrOk;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TPersonDlg::aciCloseExecute(TObject *Sender) {
	ModalResult = mrClose;
}
// ---------------------------------------------------------------------------

void __fastcall TPersonDlg::Info(int person_id) {
	try {
		Caption = "Podgl¹d danych klienta (id: " + IntToStr(person_id) + ")";

		btSave->Action = aciClose;

		aciCancel->Visible = false;

		dnaNavigator->VisibleButtons =
			dnaNavigator->VisibleButtons >> nbInsert >> nbDelete >> nbEdit >>
			nbPost >> nbCancel;
		dnaNavigator->Width = 104;

		cbRodzajDok->Enabled = false;
		cbRodzajAdr->Enabled = false;

		PersonModule->Open(person_id);

		ShowModal();

		PersonModule->Close();
	}
	catch (Exception& exc) {
		PersonModule->Close();

		Application->ShowException(&exc);
	}
}
// ------------------------------------------------------------------------------

int __fastcall TPersonDlg::Append() {
	int client_id = -1;

	try {
		Caption = "Dodawanie nowego klienta";

		btSave->Action = aciSave;

		aciCancel->Visible = true;

		dnaNavigator->VisibleButtons =
			dnaNavigator->VisibleButtons << nbInsert << nbDelete << nbEdit <<
			nbPost << nbCancel;
		dnaNavigator->Width = 234;

		cbRodzajDok->Enabled = true;
		cbRodzajAdr->Enabled = true;

		PersonModule->Append();

		if (ShowModal() == mrOk) {
			client_id = PersonModule->GetPersonID();
		}

		PersonModule->Close();
	}
	catch (Exception& exc) {
		PersonModule->Close();

		Application->ShowException(&exc);
	}

	return client_id;
}
// ------------------------------------------------------------------------------

bool __fastcall TPersonDlg::Edit(int person_id) {
	bool modified = false;

	try {
		Caption = "Edycja danych klienta (id: " + IntToStr(person_id) + ")";

		btSave->Action = aciSave;

		aciCancel->Visible = true;

		dnaNavigator->VisibleButtons =
			dnaNavigator->VisibleButtons << nbInsert << nbDelete << nbEdit <<
			nbPost << nbCancel;
		dnaNavigator->Width = 234;

		cbRodzajDok->Enabled = true;
		cbRodzajAdr->Enabled = true;

		PersonModule->Open(person_id);

		PersonModule->Edit();

		if (ShowModal() == mrOk) {
			modified = true;
		}

		PersonModule->Close();
	}
	catch (Exception& exc) {
		PersonModule->Close();

		Application->ShowException(&exc);
	}

	return modified;
}
// ------------------------------------------------------------------------------

bool __fastcall TPersonDlg::Erase(int person_id) {
	if (Application->MessageBox
		(_T("Czy na pewno usun¹æ dane wybranego klienta?"),
		_T("Usuwanie danych klienta"), MB_YESNO | MB_DEFBUTTON2) != IDYES) {
		return false;
	}

	bool erased = false;

	try {
		PersonModule->Open(person_id);

		PersonModule->Erase();

		PersonModule->ApplyUpdates();

		PersonModule->Close();

		erased = true;
	}
	catch (Exception& exc) {
		PersonModule->CancelUpdates();

		PersonModule->Close();

		Application->ShowException(&exc);
	}

	return erased;
}
// ------------------------------------------------------------------------------
