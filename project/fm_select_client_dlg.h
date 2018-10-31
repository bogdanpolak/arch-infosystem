//---------------------------------------------------------------------------

#ifndef fm_select_client_dlgH
#define fm_select_client_dlgH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------

/*
* Okno dialogowe do wybrania jednego z wyœwietlonych klientów.
*/

class TSelectClientDlg : public TForm
{
__published:	// IDE-managed Components
   TPanel *Panel1;
   TPanel *Panel2;
   TDataSource *DataSource1;
   TDBGrid *DBGrid1;
   TButton *Button1;
   TButton *Button2;
   void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall TSelectClientDlg(TComponent* Owner);


   /*
   * Wyœwietlenie okna z list¹ klientów do wyboru.
   * Przed wywo³aniem funkcji nale¿y pod³¹czyæ komponent DataSource1 do w³aœciwego
   * Ÿród³a danych (lista klientów).
   * Funkcja zwraca identyfikator wybranego klienta lub -1 przy braku wyboru.
   */
   int __fastcall Select();

};

#endif
