//---------------------------------------------------------------------------

#ifndef fm_seek_client_dlgH
#define fm_seek_client_dlgH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------

/*
* Okno dialogowe do wyszukiwania klientów po identyfiaktorze lub nazwie.
*/

class TSeekClientDlg : public TForm
{
__published:	// IDE-managed Components
   TGroupBox *GroupBox1;
   TEdit *Edit1;
   TButton *Button1;
   void __fastcall Button1Click(TObject *Sender);
   void __fastcall FormShow(TObject *Sender);
   void __fastcall Edit1KeyPress(TObject *Sender, System::WideChar &Key);
private:	// User declarations
   int    m_clientID;
   String m_clientKind;  // rodzaj osoby: F - fizyczna, P - firma

public:		// User declarations
   __fastcall TSeekClientDlg(TComponent* Owner);


   int __fastcall GetClientID();

   String __fastcall GetClientKind();

   /*
   * Funkcja zwraca identyfikator znalezionego klienta lub -1 w przypadku, gdy
   * operator nie wybra³ ¿adnego klienta.
   */
   int __fastcall Display();

};
//---------------------------------------------------------------------------
extern PACKAGE TSeekClientDlg *SeekClientDlg;
//---------------------------------------------------------------------------
#endif
