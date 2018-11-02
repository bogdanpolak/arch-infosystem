// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fm_main_form.h"
#include "dm_database_module.h"
#include "fm_login_dlg.h"
#include "fm_person_dlg.h"
#include "fm_seek_client_dlg.h"
#include "fm_browser_dlg.h"
#include "user_info.h"
#include <memory>
#include "fm_property_account_dlg.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
// ---------------------------------------------------------------------------

__fastcall TMainForm::TMainForm(TComponent* Owner) : TForm(Owner) {
}
// ---------------------------------------------------------------------------

void __fastcall TMainForm::updateControls() {
	klienci::UserInfo user(DatabaseModule->GetUser());

	bool logged = DatabaseModule->IsUserLogged();
	bool active = (user.Status == klienci::UserInfo::ustActive);

	btKlientDodaj->Enabled = logged && active;
	btKlientAkt->Enabled = logged && active;
	btKlientBaza->Enabled = logged && active;

	switch (user.Status) {
	case klienci::UserInfo::ustActive:
		stUser->Caption = user.Name;
		break;

	case klienci::UserInfo::ustBlocked:
		stUser->Caption = _T("<zablokowany> ") + user.Name;
		break;

	case klienci::UserInfo::ustSuspended:
		stUser->Caption = _T("<zawieszony> ") + user.Name;
		break;

	case klienci::UserInfo::ustErased:
		stUser->Caption = _T("<wykreœlony> ") + user.Name;
		break;
	}
}
// ------------------------------------------------------------------------------

void __fastcall TMainForm::FormShow(TObject *Sender) {
	updateControls();
}
// ---------------------------------------------------------------------------

void __fastcall TMainForm::stUserDblClick(TObject *Sender) {
	std::auto_ptr<TLoginDlg>dlg(new TLoginDlg(this));

	dlg->Login();

	updateControls();
	setupControlsAfterLogin();

}
// ---------------------------------------------------------------------------

void __fastcall TMainForm::btKlientDodajClick(TObject *Sender) {
	klienci::UserInfo user(DatabaseModule->GetUser());

	if (user.Status != klienci::UserInfo::ustActive) {
		ShowMessage(_T("Zalogowany operator nie jest czynny."));

		return;
	}

	if (!user.checkRight(klienci::UserInfo::uacAdd)) {
		ShowMessage(_T("Brak uprawnienia do dodawania nowych klientów."));

		return;
	}

	PersonDlg->Append();
}
// ---------------------------------------------------------------------------

void __fastcall TMainForm::btKlientAktClick(TObject *Sender) {
	klienci::UserInfo user(DatabaseModule->GetUser());

	if (user.Status != klienci::UserInfo::ustActive) {
		ShowMessage(_T("Zalogowany operator nie jest czynny."));

		return;
	}

	if (!user.checkRight(klienci::UserInfo::uacEdit)) {
		ShowMessage(_T("Brak uprawnienia do aktualizowania danych klientów."));

		return;
	}

	int client_id;

	client_id = SeekClientDlg->Display();

	if (client_id > 0) {
		if (SeekClientDlg->GetClientKind() != _T("F")) {
			// ta wersje obs³uguje tylko osoby fizyczne; obs³uga firm w kolejnej wersji

			ShowMessage(_T("Nieobs³ugiwany rodzaj klienta: '") +
				SeekClientDlg->GetClientKind() + _T("'"));
		}
		else {
			PersonDlg->Edit(client_id);
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TMainForm::btKlientBazaClick(TObject *Sender) {
	klienci::UserInfo user(DatabaseModule->GetUser());

	if (user.Status != klienci::UserInfo::ustActive) {
		ShowMessage(_T("Zalogowany operator nie jest czynny."));

		return;
	}

	if (!user.checkRight(klienci::UserInfo::uacBrowse)) {
		ShowMessage(_T("Brak uprawnienia dostêpu do bazy klientów."));

		return;
	}

	BrowserDlg->ShowModal();
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::btPropertyAccountClick(TObject *Sender) {
	PropertyAccount->Show();
}
// ---------------------------------------------------------------------------

boolean __fastcall TMainForm::inDeveloperMode() {
#if defined _DEBUG
	String projFileName = ChangeFileExt(ExtractFileName(Application->ExeName),
		".cbproj");
	bool isDeveloperLocation = FileExists("..\\..\\"+projFileName);
	return isDeveloperLocation;
#else
	return false;
#endif
}

// ---------------------------------------------------------------------------
boolean __fastcall TMainForm::setupControlsAfterLogin() {
	Label1->Visible = false;
	Label2->Visible = false;
	Label3->Visible = false;
	TWinControl* ParentControl = gbxLogin;
	TControl* ChildControl;
	int maxBottom = 0;
	for (int i = 0; i < ParentControl->ControlCount; i++) {
		ChildControl = ParentControl->Controls[i];
		if (ChildControl->Visible) {
			int bottom = ChildControl->Top + ChildControl->Height;
			if (ChildControl->AlignWithMargins) {
				bottom += ChildControl->Margins->Bottom;
			}
			if (bottom > maxBottom) {
				maxBottom = bottom;
			}
		}
	}
	if (ParentControl->AlignWithMargins) {
		maxBottom += ParentControl->Padding->Bottom;
	}
	gbxLogin->Height = maxBottom + 8;
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::acAutoLoginExecute(TObject *Sender) {
	if (inDeveloperMode()) {
		DatabaseModule->Login("admin", "admin");
		updateControls();
		setupControlsAfterLogin();
	}
}
// ---------------------------------------------------------------------------
