//---------------------------------------------------------------------------

#ifndef FormTwoUH
#define FormTwoUH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "Messaging_EventBus.h"
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm, public TSubscriber
{
__published:	// IDE-managed Components
	TTimer *tmrAnimate;
	TLabel *Label1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall tmrAnimateTimer(TObject *Sender);
private:	// User declarations
    unsigned int DefualtTimerInterval;
	void EvenBusOnChangeSpeed (int MessageID, TEvenMessage *message);
	void EvenBusOnChangeColor (int MessageID, TEvenMessage *message);
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
	virtual void OnEvent (int MessageID, TEvenMessage *message);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
