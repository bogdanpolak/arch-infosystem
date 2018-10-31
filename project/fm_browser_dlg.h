//---------------------------------------------------------------------------

#ifndef fm_browser_dlgH
#define fm_browser_dlgH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
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
#include <Vcl.DBCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TBrowserDlg : public TForm
{
__published:	// IDE-managed Components
   TPanel *Panel1;
   TPanel *Panel2;
   TDataSource *DataSource1;
   TDBGrid *DBGrid1;
   TDBNavigator *DBNavigator1;
   TFDQuery *FDQuery1;
   TButton *btInfo;
   TButton *btEdit;
   TButton *btErase;
   TButton *Button4;
   TButton *btAppend;
   void __fastcall FormShow(TObject *Sender);
   void __fastcall btInfoClick(TObject *Sender);
   void __fastcall btAppendClick(TObject *Sender);
   void __fastcall btEditClick(TObject *Sender);
   void __fastcall btEraseClick(TObject *Sender);
   void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:	// User declarations

   int __fastcall getCurrentClientID();

   /*
   * Sprawdzenie, czy osoba z bie¿¹cego rekordu jest obs³ugiwana.
   * Bie¿¹ca wersja nie obs³uguje firm.
   */
   bool __fastcall isServiced();

   void __fastcall refreshData(int client_id);

public:		// User declarations
   __fastcall TBrowserDlg(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBrowserDlg *BrowserDlg;
//---------------------------------------------------------------------------
#endif
