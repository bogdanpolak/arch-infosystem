// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("fm_seek_client_dlg.cpp", SeekClientDlg);
USEFORM("fm_property_account_dlg.cpp", PropertyAccount);
USEFORM("fm_person_dlg.cpp", PersonDlg);
USEFORM("dm_person_module.cpp", PersonModule); /* TDataModule: File Type */
USEFORM("dm_database_module.cpp", DatabaseModule); /* TDataModule: File Type */
USEFORM("fm_main_form.cpp", MainForm);
USEFORM("fm_login_dlg.cpp", LoginDlg);
USEFORM("fm_browser_dlg.cpp", BrowserDlg);
USEFORM("dm_property_module.cpp", PropertyModule); /* TDataModule: File Type */
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
   try
   {
      Application->Initialize();
      Application->MainFormOnTaskBar = true;
      Application->CreateForm(__classid(TMainForm), &MainForm);
		Application->CreateForm(__classid(TPropertyAccount), &PropertyAccount);
		Application->CreateForm(__classid(TDatabaseModule), &DatabaseModule);
		Application->CreateForm(__classid(TPersonModule), &PersonModule);
		Application->CreateForm(__classid(TBrowserDlg), &BrowserDlg);
		Application->CreateForm(__classid(TPersonDlg), &PersonDlg);
		Application->CreateForm(__classid(TPropertyAccount), &PropertyAccount);
		Application->CreateForm(__classid(TSeekClientDlg), &SeekClientDlg);
		Application->Run();
	}
	catch (Exception &exception) {
		Application->ShowException(&exception);
	}
	catch (...) {
		try {
			throw Exception("");
		}
		catch (Exception &exception) {
			Application->ShowException(&exception);
		}
	}
	return 0;
}
// ---------------------------------------------------------------------------
