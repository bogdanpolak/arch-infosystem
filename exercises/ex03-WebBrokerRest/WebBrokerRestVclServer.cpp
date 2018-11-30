
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
#include <Web.WebReq.hpp>
#ifdef USEPACKAGES
#pragma link "IndySystem.bpi"
#pragma link "IndyCore.bpi"
#pragma link "IndyProtocols.bpi"
#else
#pragma comment(lib, "IndySystem")
#pragma comment(lib, "IndyCore")
#pragma comment(lib, "IndyProtocols")
#endif
#pragma link "IdHTTPWebBrokerBridge"

//---------------------------------------------------------------------------
USEFORM("web_employee.cpp", WebModule1); /* TWebModule: File Type */
USEFORM("frm_main.cpp", Form1);
//---------------------------------------------------------------------------
extern PACKAGE TComponentClass WebModuleClass;
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
  try
  {
    if (WebRequestHandler() != NULL)
    {
      WebRequestHandler()->WebModuleClass = WebModuleClass;
    }
    Application->Initialize();
	Application->CreateForm(__classid(TForm1), &Form1);
		Application->Run();
  }
  catch (Exception &exception)
  {
    Sysutils::ShowException(&exception, System::ExceptAddr());
  }
  return 0;
}
//---------------------------------------------------------------------------



