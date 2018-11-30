 
//---------------------------------------------------------------------------
#ifndef web_employeeH
#define web_employeeH
//---------------------------------------------------------------------------
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <Web.HTTPApp.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.IB.hpp>
#include <FireDAC.Phys.IBDef.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <FireDAC.Phys.FB.hpp>
#include <FireDAC.Phys.FBDef.hpp>
//---------------------------------------------------------------------------
class TWebModule1 : public TWebModule
{
__published:	// IDE-managed Components
	TFDConnection *FDConnection1;
	TFDQuery *dsEmployee;
	TSmallintField *dsEmployeeEMP_NO;
	TStringField *dsEmployeeFIRST_NAME;
	TStringField *dsEmployeeLAST_NAME;
	TStringField *dsEmployeePHONE_EXT;
	TSQLTimeStampField *dsEmployeeHIRE_DATE;
	TStringField *dsEmployeeDEPT_NO;
	TStringField *dsEmployeeDepartmentName;
	TStringField *dsEmployeeJOB_CODE;
	TStringField *dsEmployeeJobName;
	TSmallintField *dsEmployeeJOB_GRADE;
	TStringField *dsEmployeeJOB_COUNTRY;
	TBCDField *dsEmployeeSALARY;
	TStringField *dsEmployeeFULL_NAME;
	TStringField *dsEmployeeJobPosition;
	TFDQuery *dsJob;
	TFDQuery *dsDepartment;
	void __fastcall WebModule1DefaultHandlerAction(TObject *Sender, TWebRequest *Request,
          TWebResponse *Response, bool &Handled);
private:	// User declarations
	void ApiGetVersion(TWebResponse *Response);
	void ApiGetNotImplemented(TWebResponse *Response);
	void ApiGetEmployee(TWebResponse *Response);
	void ApiPostEmployee(TWebRequest *Request, TWebResponse *Response);
public:		// User declarations
	__fastcall TWebModule1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TWebModule1 *WebModule1;
//---------------------------------------------------------------------------
#endif


