//---------------------------------------------------------------------------

#pragma hdrstop

#include "mvc_work.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

using namespace mvc;

__fastcall TWork::TWork(TComponent* AOwner) : TComponent(AOwner)
{
  FAction = new TAction(this);

  FAction->OnExecute = ExecuteEvent;
}

void __fastcall TWork::ExecuteEvent(TObject* Sender)
{
  DoWork();
}

TAction* __fastcall TWork::GetAction()
{
  FAction->Caption = FCaption;
  return FAction;
}

void __fastcall TWork::SetCaption(String ACaption)
{
  FCaption = ACaption;
  FAction->Caption = ACaption;
}

void __fastcall TWork::SetActionEnable(bool Enable)
{
  FAction->Enabled = Enable;
}

