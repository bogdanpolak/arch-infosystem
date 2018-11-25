// ---------------------------------------------------------------------------

#ifndef user_infoH
#define user_infoH
// ---------------------------------------------------------------------------
#include <System.hpp>
#include <vector>
// ---------------------------------------------------------------------------

namespace klienci {

	class UserInfo {
	public:

		enum UserStatus {
			ustActive = 'A', // operator czynny
			ustBlocked = 'B', // operator zablokowany (kilka prób nieudanego zalogowania)
			ustSuspended = 'U', // operator zwieszony (dzia³anie administratora)
			ustErased = 'Z', // operator wykreœlony
			ustUndefined = '?'
		};

		// Rodzaj czynnoœci do wykonania
		enum UserAction {
			uacView, // tylko podgl¹d
			uacEdit, // edycja i podgl¹d
			uacErase, // usuwanie i podgl¹d
			uacAdd, // dodawanie
			uacBrowse, // przegl¹danie
			uacPayment // zaksiêgowanie wp³aty
		};

		// Oznaczenie systemu
		enum System {
			sysBO, // baza osobowa
			sysPD // podatki od nieruchomoœci
		};

		static UserStatus stringToUserStatus(const String& status);

		typedef std::vector<String> UserRights;

		int Ident;
		String Name;
		String Password;
		String Forename;
		String Surname;
		UserStatus Status;
		UserRights Rights;

		UserInfo();

		bool isDefined() const ;
		bool checkRight(const String& right) const ;
		bool checkRight(UserAction action, System system = sysBO) const ;
	};
}

#endif
