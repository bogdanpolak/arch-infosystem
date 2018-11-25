//---------------------------------------------------------------------------

#ifndef dm_database_moduleH
#define dm_database_moduleH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Phys.FB.hpp>
#include <FireDAC.Phys.FBDef.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Stan.Param.hpp>
#include "user_info.h"
//---------------------------------------------------------------------------
class TDatabaseModule : public TDataModule
{
__published:	// IDE-managed Components
   TFDConnection *ConnectionDB;
   TFDQuery *UserData;
   TFDQuery *UserRights;
   TFDQuery *SelectData;
private:	// User declarations
   klienci::UserInfo m_user;

public:		// User declarations
   __fastcall TDatabaseModule(TComponent* Owner);
   bool __fastcall IsUserLogged();
   bool IsValidDatabaseVersion();
   klienci::UserInfo __fastcall GetUser();
   bool __fastcall Login(const String user, const String passw);
};
//---------------------------------------------------------------------------
extern PACKAGE TDatabaseModule *DatabaseModule;
//---------------------------------------------------------------------------
#endif
