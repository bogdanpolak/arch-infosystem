//---------------------------------------------------------------------------

#ifndef FormMainH
#define FormMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TTimer *tmrReady;
	TGroupBox *GroupBox2;
	TStringGrid *StringGrid1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall tmrReadyTimer(TObject *Sender);
private:	// User declarations
	TAction* actConfirmPerson;
	TEdit* edtFirstName;
	TEdit* edtLastName;
	TLabel* lblPersonValidatorInfo;
	void __fastcall BuildControlsInCode(TWinControl* aOwner);
	void __fastcall actConfirmPersonExecute(TObject* Sender);
	void __fastcall actConfirmPersonUpdate(TObject* Sender);
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
