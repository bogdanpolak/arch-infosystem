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
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------

/*
* Okno dialogowe od obsługi pojedynczego konta podatkowego.
* Główne dane pobierane z tabeli PD_KONTA:
*    select * from PD_KONTA where id_konta = :ID_KONTA
* Lista składników nieruchomości:
*    select * from PD_SKLADNIKI where id_konta = :ID_KONTA
* Lista podatników podatku od nieruchomości:
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
	TFDQuery *FDQuery1;
	TDataSource *DataSource1;
	TDBGrid *DBGrid1;
	TDataSource *DataSource2;
	TFDQuery *FDQuery2;
	TDataSource *DataSource3;
	TFDQuery *FDQuery3;
	TDBGrid *DBGrid2;
	TDBGrid *DBGrid3;
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
