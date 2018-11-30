//---------------------------------------------------------------------------

#ifndef mvc_workH
#define mvc_workH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <VCL.ActnList.hpp>
//---------------------------------------------------------------------------

namespace mvc
{

	class TWork : public TComponent
	{
	private:
		String FCaption;
		TAction* FAction;

		TAction* __fastcall GetAction();

		void __fastcall SetCaption(String ACaption);

		void __fastcall ExecuteEvent(TObject* Sender);

	public:

		__fastcall TWork(TComponent* AComponent);

		virtual bool __fastcall DoWork() = 0;

		void __fastcall SetActionEnable(bool Enable);

		__property String Caption = { read = FCaption, write = SetCaption };
		__property TAction* Action = { read = GetAction };

	};
}


#endif
