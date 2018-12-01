//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <System.Threading.hpp>
//---------------------------------------------------------------------------
#include "form_main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner) {
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

#ifdef __clang__
void TForm1::RunDemo(TMemo *AMemo) {
	TTask::Run(
		[this,AMemo]()-> void {
			TMemo* TaskMemo = AMemo;
			const int iter = 10;
			const int sleepTime = 500;
			for (int i=0; i<iter; ++i) {
				Sleep(sleepTime);
				TThread::Synchronize (0,
					[this, i, TaskMemo]() -> void {
						String str(TimeToStr(Now()));
						String message = str + ((i<iter-1) ?
							" [working]" :
							" DONE!!!");
						TaskMemo->Lines->Add( message );
					}
				);
			}
			TaskMemo->Lines->Add("");
			for (int i=5; i>0; --i) {
				Sleep(sleepTime);
				TThread::Synchronize (0,
					[this, i, TaskMemo]() -> void {
						TaskMemo->Lines->Text += i;
					}
				);
			}
			TaskMemo->Tag = -1;
		}
	);

}
#else
class TMemoLinesAddSync : public TCppInterfacedObject<TThreadProcedure> {
	TMemo* AsyncMemo;
	String Message;
public:
	TMemoLinesAddSync(TMemo* mm, String msg): AsyncMemo(mm), Message(msg)
	{}
	void __fastcall Invoke(){
		AsyncMemo->Lines->Add( Message );
	}
};

class TReportMemoTask : public TCppInterfacedObject<TProc> {
private:
	int taskLength;
	TMemo* TaskMemo;
	void _Memo_ReportMessage (String msg) {
		TThread::Synchronize (0,
			_di_TThreadProcedure(new TMemoLinesAddSync(TaskMemo, msg)) );
	}
public:
	TReportMemoTask(int length, TMemo* mm): taskLength(length), TaskMemo(mm)
	{}
	void __fastcall Invoke(){
		// [zobacz] TTask::WaitForAll(...)
		// [zobacz] TTask::WaitForAny(...)
		const int sleepTime = 100;
		String msg = String().sprintf(L"Starting ...  %d steps",taskLength);
		_Memo_ReportMessage (msg);
		for (int i=0; i<taskLength; ++i) {
			Sleep(sleepTime);
			msg = String().sprintf(L"%s : (%d)",TimeToStr(Now()),i+1);
			_Memo_ReportMessage ( msg );
		}
		_Memo_ReportMessage ( "----- Done -----" );
		_Memo_ReportMessage ( "Closing ... (~1.5 ms)" );
		Sleep(1500);
		TaskMemo->Tag = -1;
	}
};

void TForm1::RunDemo(TMemo *AMemo) {
	int reportLength = 45+random(20);
	TTask::Run( _di_TProc(new TReportMemoTask(reportLength,AMemo)) );
}
#endif
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	randomize();
	GroupBox2->Align = alClient;
}

//---------------------------------------------------------------------------
String TForm1::GetCompilerInfo() {
#if !defined(__clang__) && defined(_WIN32) && !defined(_WIN64)
	return "Classic Win32 C++ compiler";
#endif
#if defined(__clang__) && defined(_WIN32) && !defined(_WIN64)
	return "Win32 C++ Clang compiler";
#endif
#ifdef _WIN64
	return "Win64 C++ Clang compiler";
#endif
	// #ifdef __BORLANDC__

}
//---------------------------------------------------------------------------

TMemo* TForm1::InsertMemo(TWinControl* container) {
	TMemo* mm = new TMemo(container);
	mm->AlignWithMargins = true;
	mm->Left = 9999;
	mm->Align = alLeft;
	mm->Width = 150;
	mm->Parent = container;
	return mm;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnCheckCompilerClick(TObject *Sender) {
	String theCompiler = this->GetCompilerInfo();
	btnCheckCompiler->Caption = theCompiler;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnAddTaskClick(TObject *Sender)
{
	TMemo* mm = InsertMemo(GroupBox2);
	RunDemo (mm);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnAdd3TasksClick(TObject *Sender)
{
	int const taskCounter = 3;
	for (int i = 0; i<taskCounter; ++i) {
		TMemo* mm = InsertMemo(GroupBox2);
		RunDemo (mm);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::tmrIdleTimer(TObject *Sender)
{
	TWinControl* container = GroupBox2;
	for (int i=0; i < container->ControlCount; ++i) {
		TMemo* mm = dynamic_cast<TMemo*>(container->Controls[i]);
		if (mm && mm->Tag==-1) {
			TBevel* bv = new TBevel(container);
			bv->AlignWithMargins = true;
            bv->Shape = bsSpacer;
			bv->Left = 0;
			bv->Align = alLeft;
			bv->Width = mm->Width;
			bv->Parent = container;
			delete mm;
		}
		TBevel* bv = dynamic_cast<TBevel*>(container->Controls[i]);
		if (bv) {
			if (bv->Width>20)
				bv->Width = bv->Width - 20;
			else
				delete bv;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnMoreInfoAboutDemoClick(TObject *Sender)
{
	TMemo* mm = new TMemo (this);
	mm->Align = alBottom;
    mm->AlignWithMargins = true;
	mm->Height = 48;
    mm->Parent = this;
	mm->Lines->Add ("Dokumentacja na docwiki:");
	mm->Lines->Add ("http://docwiki.embarcadero.com/RADStudio/Tokyo/en/Using_the_Parallel_Programming_Library");
}
//---------------------------------------------------------------------------

