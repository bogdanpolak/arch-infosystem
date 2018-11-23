// ---------------------------------------------------------------------------

#ifndef Form_MainH
#define Form_MainH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>

// ---------------------------------------------------------------------------
#include <vector>

// ---------------------------------------------------------------------------
class TForm1 : public TForm {
__published: // IDE-managed Components
	TGroupBox *GroupBox1;
	TSplitter *Splitter1;
	TMemo *Memo1;
	TButton *btnClearLog;
	TPageControl *PageControl1;
	TTabSheet *tshVector;
	TTabSheet *tshMap;
	TLabel *Label4;
	TButton *btnCapasity;
	TLabel *Label1;
	TButton *btnElementAccess;
	TLabel *Label5;
	TButton *btnIterators;
	TLabel *Label2;
	TButton *btnSortInt;
	TButton *btnBinarySerachInt;
	TButton *btnStructDemo;
	TLabel *Label3;
	TButton *btnFillCustomersMap;
	TButton *btnFindMapKey;
	TButton *btnFilterMap;

	void __fastcall btnCapasityClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall btnClearLogClick(TObject *Sender);
	void __fastcall btnSortIntClick(TObject *Sender);
	void __fastcall btnIteratorsClick(TObject *Sender);
	void __fastcall btnElementAccessClick(TObject *Sender);
	void __fastcall btnStructDemoClick(TObject *Sender);
	void __fastcall btnBinarySerachIntClick(TObject *Sender);
	void __fastcall btnFillCustomersMapClick(TObject *Sender);
	void __fastcall btnFindMapKeyClick(TObject *Sender);
	void __fastcall btnFilterMapClick(TObject *Sender);

private: // User declarations
	void ReportCompilerPlatform();
	void Log(String LogMessage);
	void LogSparator();
	void LogMessageAndInt(String Message, int value);
	void LogVectorElems(int ident, const std::vector<int> vector);

public: // User declarations
	__fastcall TForm1(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
// ---------------------------------------------------------------------------
#endif
