//---------------------------------------------------------------------------

#ifndef dm_property_moduleH
#define dm_property_moduleH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
//---------------------------------------------------------------------------
class TPropertyModule : public TDataModule
{
__published:	// IDE-managed Components
	TFDQuery *quKonta;
	TFDQuery *quSkladniki;
	TDataSource *dsKonta;
	TFDQuery *quPodatnicy;
private:	// User declarations
public:		// User declarations
	__fastcall TPropertyModule(TComponent* Owner);

	void __fastcall Open();
};
//---------------------------------------------------------------------------
#endif
