// ---------------------------------------------------------------------------

#ifndef FormMainUH
#define FormMainUH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>

// ---------------------------------------------------------------------------
class TFormMain : public TForm {
__published: // IDE-managed Components
	TButton *btnShowSubscribers;
	TButton *btnPostMessage1;
	TGroupBox *GroupBox1;
	TEdit *Edit1;
	TBevel *Bevel1;
	TBevel *Bevel2;
	TCheckBox *chkFastAnimataion;
	TButton *btnExit;
	TBevel *Bevel3;
	TColorBox *ColorBox1;
	TBevel *Bevel4;
	TGridPanel *GridPanel1;
	TButton *btnPause;
	TButton *btnAnimate;

	void __fastcall btnShowSubscribersClick(TObject *Sender);
	void __fastcall btnPostMessage1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall chkFastAnimataionClick(TObject *Sender);
	void __fastcall btnExitClick(TObject *Sender);
	void __fastcall ColorBox1Change(TObject *Sender);
	void __fastcall btnPauseClick(TObject *Sender);
	void __fastcall btnAnimateClick(TObject *Sender);

private: // User declarations
	void __fastcall UpdateControlsEnable(bool Registered);

public: // User declarations
	__fastcall TFormMain(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
// ---------------------------------------------------------------------------
#endif
