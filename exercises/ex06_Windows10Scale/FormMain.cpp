// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormMain.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender) {
	actConfirmPerson = new TAction(this);
	actConfirmPerson->Caption = "ZatwierdŸ";
	actConfirmPerson->OnExecute = actConfirmPersonExecute;
	actConfirmPerson->OnUpdate = actConfirmPersonUpdate;
	StringGrid1->Rows[0]->Text = " \nImiê\nNazwisko";
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::tmrReadyTimer(TObject *Sender) {
	tmrReady->Enabled = false;
	BuildControlsInCode(GroupBox1);
	int GridColumnWidth = this->Canvas->TextWidth("Lorem Ipsum dolres");
	StringGrid1->ColWidths[1] = GridColumnWidth;
	StringGrid1->ColWidths[2] = GridColumnWidth;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::BuildControlsInCode(TWinControl* aOwner) {
	int TextHeight = -this->Canvas->Font->Height;
	TLabel* lbl01 = new TLabel(aOwner); {
		lbl01->AutoSize = False;
		lbl01->Caption = "Imiê";
		lbl01->AlignWithMargins = True;
		lbl01->Margins->Bottom = 0;
		lbl01->Top = 999;
		lbl01->Parent = aOwner;
		lbl01->Align = alTop;
		lbl01->AutoSize = True;
	};
	edtFirstName = new TEdit(aOwner); {
		edtFirstName->Text = "Bogdan";
		edtFirstName->Align = alTop;
		edtFirstName->AlignWithMargins = True;
		edtFirstName->Top = 999;
		edtFirstName->Parent = aOwner;
	};
	TLabel* lbl02 = new TLabel(aOwner); {
		lbl02->AutoSize = False;
		lbl02->Caption = "Nazwisko";
		lbl02->AlignWithMargins = True;
		lbl02->Margins->Bottom = 0;
		lbl02->Top = 999;
		lbl02->Parent = aOwner;
		lbl02->Align = alTop;
		lbl02->AutoSize = True;
	};
	edtLastName = new TEdit(aOwner);
	{
		edtLastName->Name = "edtLastName";
		edtLastName->Text = "Polak";
		edtLastName->Align = alTop;
		edtLastName->AlignWithMargins = True;
		edtLastName->Top = 999;
		edtLastName->Parent = aOwner;
	};
	lblPersonValidatorInfo = new TLabel(aOwner); {
		lblPersonValidatorInfo->AutoSize = False;
		lblPersonValidatorInfo->Font->Color = clGray;
		lblPersonValidatorInfo->Font->Style = TFontStyles() << fsItalic;
		lblPersonValidatorInfo->Font->Height = -11;
		lblPersonValidatorInfo->Caption =
			"Proszê wprowadziæ wszystkie wymagane pola, aby dodaæ osobê.";
		lblPersonValidatorInfo->Align = alTop;
		lblPersonValidatorInfo->AlignWithMargins = True;
		lblPersonValidatorInfo->WordWrap = True;
		lblPersonValidatorInfo->Top = 999;
		lblPersonValidatorInfo->Parent = aOwner;
		lblPersonValidatorInfo->AutoSize = True;
	};
	TButton* btn01 = new TButton(aOwner); {
		btn01->Name = "btnConfirm";
		btn01->Action = actConfirmPerson;
		btn01->Align = alTop;
		btn01->AlignWithMargins = True;
		btn01->Margins->Top = (int)(1.5 * TextHeight);
		btn01->Top = 999;
		btn01->Parent = aOwner;
		btn01->Height = (int)(2.5 * TextHeight);
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::actConfirmPersonExecute(TObject* Sender) {
	int aRow = StringGrid1->RowCount - 1;
	StringGrid1->Cells[1][aRow] = edtFirstName->Text;
	StringGrid1->Cells[2][aRow] = edtLastName->Text;
	StringGrid1->RowCount = StringGrid1->RowCount + 1;
	edtFirstName->Text = "";
	edtLastName->Text = "";
	edtFirstName->SetFocus();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::actConfirmPersonUpdate(TObject* Sender) {
	bool isValid = (Trim(edtFirstName->Text)!="") &&
		(Trim(edtLastName->Text)!="");
	actConfirmPerson->Enabled = isValid;
	lblPersonValidatorInfo->Visible = !isValid;
}
// ---------------------------------------------------------------------------
