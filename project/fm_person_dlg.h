//---------------------------------------------------------------------------

#ifndef fm_person_dlgH
#define fm_person_dlgH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
//---------------------------------------------------------------------------

/*
* Okno dialogowe do obs³ugi klientów bêd¹cych osobami fizycznymi.
*/

class TPersonDlg : public TForm
{
__published:	// IDE-managed Components
   TPanel *Panel1;
   TPanel *Panel2;
   TPanel *Panel3;
   TLabel *Label1;
   TLabel *Label2;
   TLabel *Label3;
   TLabel *Label4;
   TLabel *Label5;
   TLabel *Label6;
   TLabel *Label7;
   TLabel *Label8;
   TLabel *Label9;
   TLabel *Label10;
   TDataSource *dsPerson;
   TDataSource *dsAddress;
   TDBEdit *DBEdit1;
   TDBEdit *DBEdit2;
   TDBEdit *DBEdit3;
   TDBEdit *DBEdit4;
   TDBEdit *DBEdit5;
   TDBEdit *DBEdit6;
   TDBEdit *DBEdit7;
   TDBEdit *DBEdit8;
   TDBEdit *DBEdit9;
   TDBEdit *DBEdit10;
   TGroupBox *GroupBox1;
   TLabel *Label11;
   TLabel *Label12;
   TDBEdit *DBEdit11;
   TComboBox *cbRodzajDok;
   TPanel *Panel4;
   TPanel *Panel5;
   TPanel *Panel6;
   TPanel *Panel7;
   TPanel *Panel8;
   TDBGrid *DBGrid1;
   TDBNavigator *dnaNavigator;
   TLabel *Label13;
   TLabel *Label14;
   TLabel *Label15;
   TLabel *Label16;
   TLabel *Label17;
   TLabel *Label18;
   TLabel *Label19;
   TDBEdit *DBEdit12;
   TDBEdit *DBEdit13;
   TDBEdit *DBEdit14;
   TDBEdit *DBEdit15;
   TDBEdit *DBEdit16;
   TDBComboBox *DBComboBox1;
   TDBEdit *DBEdit17;
   TLabel *Label20;
   TComboBox *cbRodzajAdr;
   TButton *btSave;
   TButton *btCancel;
   TActionList *ActionList1;
   TAction *aciCancel;
   TAction *aciSave;
   TAction *aciClose;
   void __fastcall FormShow(TObject *Sender);
   void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
   void __fastcall dsAddressDataChange(TObject *Sender, TField *Field);
   void __fastcall dsAddressUpdateData(TObject *Sender);
   void __fastcall dsPersonUpdateData(TObject *Sender);
   void __fastcall aciCancelExecute(TObject *Sender);
   void __fastcall aciSaveExecute(TObject *Sender);
   void __fastcall aciCloseExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall TPersonDlg(TComponent* Owner);


   void __fastcall Info(int person_id);

   int __fastcall Append();

   bool __fastcall Edit(int person_id);

   bool __fastcall Erase(int person_id);

};
//---------------------------------------------------------------------------
extern PACKAGE TPersonDlg *PersonDlg;
//---------------------------------------------------------------------------
#endif
