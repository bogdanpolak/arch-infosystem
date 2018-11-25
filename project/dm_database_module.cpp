// ---------------------------------------------------------------------------

#pragma hdrstop

#include "dm_database_module.h"
#include "app_globals.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma resource "*.dfm"
TDatabaseModule *DatabaseModule;
// ---------------------------------------------------------------------------

__fastcall TDatabaseModule::TDatabaseModule(TComponent* Owner)
	: TDataModule(Owner), m_user() {
	if (ConnectionDB->Connected) {
		ConnectionDB->Connected = false;
	}

	ConnectionDB->Connected = true;
}
// ---------------------------------------------------------------------------

bool __fastcall TDatabaseModule::IsUserLogged() {
	return m_user.isDefined();
}
// ------------------------------------------------------------------------------

bool TDatabaseModule::IsValidDatabaseVersion() {
	int CurrentDBVersion = ConnectionDB->ExecSQLScalar
		("SELECT max(VERSION) FROM DB_VERSIONS");
	return (AppGlobals::RequiredDatabaseVersion == CurrentDBVersion);
}
// ------------------------------------------------------------------------------

klienci::UserInfo __fastcall TDatabaseModule::GetUser() {
	return m_user;
}
// ------------------------------------------------------------------------------

bool __fastcall TDatabaseModule::Login(const String user, const String passw) {
	m_user = klienci::UserInfo();

	UserData->ParamByName("NAZWA")->AsString = user;
	UserData->ParamByName("HASLO")->AsString = passw;

	UserData->Open();

	if (!UserData->IsEmpty()) {
		m_user.Ident = UserData->FieldByName("ID_OPER")->AsInteger;
		m_user.Name = UserData->FieldByName("NAZWA")->AsString;
		m_user.Password = UserData->FieldByName("HASLO")->AsString;
		m_user.Forename = UserData->FieldByName("IMIE")->AsString;
		m_user.Surname = UserData->FieldByName("NAZWISKO")->AsString;
		m_user.Status = klienci::UserInfo::stringToUserStatus
			(UserData->FieldByName("STATUS")->AsString);

		UserRights->ParamByName("ID_OPER")->AsInteger = m_user.Ident;

		UserRights->Open();

		while (!UserRights->Eof) {
			m_user.Rights.push_back(UserRights->FieldByName("KOD_FUNSYS")
				->AsString);

			UserRights->Next();
		}

		UserRights->Close();
	}

	UserData->Close();

	return IsUserLogged();
}
// ------------------------------------------------------------------------------
