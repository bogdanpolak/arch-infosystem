//---------------------------------------------------------------------------

#ifndef fm_property_account_dlgH
#define fm_property_account_dlgH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------

/*
* Okno dialogowe od obs³ugi pojedynczego konta podatkowego.
* G³ówne dane pobierane z tabeli PD_KONTA:
*    select * from PD_KONTA where id_konta = :ID_KONTA
* Lista sk³adników nieruchomoœci:
*    select * from PD_SKLADNIKI where id_konta = :ID_KONTA
* Lista podatników podatku od nieruchomoœci:
*    select * from PD_PODATNICY where id_konta = :ID_KONTA
*/

class TPropertyAccount : public TForm
{
__published:	// IDE-managed Components
   TPanel *Panel1;
   TPanel *Panel2;
   TPanel *Panel3;
   TButton *btCancel;
   TButton *btSave;
   TPageControl *PageControl1;
   TTabSheet *TabSheet1;
   TTabSheet *TabSheet2;
   TPanel *Panel4;
   TPanel *Panel5;
private:	// User declarations
public:		// User declarations
   __fastcall TPropertyAccount(TComponent* Owner);


   void __fastcall Info(int account_id);

   int __fastcall Append();

   bool __fastcall Edit(int account_id);

   bool __fastcall Erase(int account_id);

};
//---------------------------------------------------------------------------
extern PACKAGE TPropertyAccount *PropertyAccount;
//---------------------------------------------------------------------------
#endif
