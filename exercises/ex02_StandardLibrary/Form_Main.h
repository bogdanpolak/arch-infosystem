// ---------------------------------------------------------------------------

#ifndef Form_MainH
#define Form_MainH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>

// ---------------------------------------------------------------------------
#include <vector>

// ---------------------------------------------------------------------------
class TForm1 : public TForm {
__published: // IDE-managed Components
	TGroupBox *GroupBox1;
	TSplitter *Splitter1;
	TMemo *Memo1;
	TButton *btnCapasity;
	TLabel *Label1;
	TButton *btnIterators;
	TLabel *Label2;
	TButton *btnSortIntegers;
	TLabel *Label3;
	TButton *btnClearLog;
	TButton *btnElementAccess;
	TLabel *Label4;
	TBevel *Bevel1;
	TLabel *Label5;
	TButton *btnStructDemo;

	void __fastcall btnCapasityClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall btnClearLogClick(TObject *Sender);
	void __fastcall btnSortIntegersClick(TObject *Sender);
	void __fastcall btnIteratorsClick(TObject *Sender);
	void __fastcall btnElementAccessClick(TObject *Sender);
	void __fastcall btnStructDemoClick(TObject *Sender);

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
