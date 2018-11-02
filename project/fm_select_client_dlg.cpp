// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fm_select_client_dlg.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
// ---------------------------------------------------------------------------

__fastcall TSelectClientDlg::TSelectClientDlg(TComponent* Owner) : TForm(Owner)
{
}
// ---------------------------------------------------------------------------

void __fastcall TSelectClientDlg::FormShow(TObject *Sender) {
	//
}
// ---------------------------------------------------------------------------

int __fastcall TSelectClientDlg::Select() {
	int client_id = -1;

	try {
		ShowModal();

		if (ModalResult == mrOk && !DataSource1->DataSet->IsEmpty()) {
			client_id = DataSource1->DataSet->FieldByName("ID_OSOBY")
				->AsInteger;
		}
	}
	catch (Exception& exc) {
		Application->ShowException(&exc);
	}

	return client_id;
}
// ------------------------------------------------------------------------------
