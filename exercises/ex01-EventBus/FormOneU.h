// ---------------------------------------------------------------------------

#ifndef FormOneUH
#define FormOneUH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "Messaging_EventBus.h"

// ---------------------------------------------------------------------------
class TForm1 : public TForm, public TSubscriber {
__published: // IDE-managed Components
	TListBox *ListBox1;
	TGroupBox *GroupBox1;

private: // User declarations
public: // User declarations
	__fastcall TForm1(TComponent* Owner);
	__fastcall virtual ~TForm1(void);
	virtual void OnEvent(int MessageID, TEventMessage *message);
};
// ---------------------------------------------------------------------------
#endif
