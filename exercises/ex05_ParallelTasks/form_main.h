//---------------------------------------------------------------------------

#ifndef form_mainH
#define form_mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *btnCheckCompiler;
	TGroupBox *GroupBox1;
	TGroupBox *GroupBox2;
	TTimer *tmrIdle;
	TButton *btnAddTask;
	TBevel *Bevel1;
	TButton *btnAdd3Tasks;
	TButton *btnMoreInfoAboutDemo;
	void __fastcall btnCheckCompilerClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall tmrIdleTimer(TObject *Sender);
	void __fastcall btnAddTaskClick(TObject *Sender);
	void __fastcall btnAdd3TasksClick(TObject *Sender);
	void __fastcall btnMoreInfoAboutDemoClick(TObject *Sender);
private:	// User declarations
	String GetCompilerInfo();
	TMemo* InsertMemo(TWinControl* container);
	void RunDemo(TMemo *AMemo);
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
