// ---------------------------------------------------------------------------

#pragma hdrstop

#include "user_info.h"
#include <algorithm>
// ---------------------------------------------------------------------------
#pragma package(smart_init)

namespace klienci {

	class UserInfoTools {
	public:

		static UserInfo::UserRights buildRightsForSystemBO
			(UserInfo::UserAction action) {
			UserInfo::UserRights rights;

			rights.push_back("BOS$ADM");

			switch (action) {
			case UserInfo::uacView:
				rights.push_back("BOS$INF");
				break;

			case UserInfo::uacEdit:
				rights.push_back("BOS$MOD");
				break;

			case UserInfo::uacErase:
				rights.push_back("BOS$USN");
				break;

			case UserInfo::uacAdd:
				rights.push_back("BOS$DOD");
				break;

			case UserInfo::uacBrowse:
				rights.push_back("BOS$INF");
				rights.push_back("BOS$MOD");
				rights.push_back("BOS$USN");
				rights.push_back("BOS$DOD");
				break;
			}

			return rights;
		}
		// ------------------------------------------------------------------------------

		static UserInfo::UserRights buildRightsForSystemPD
			(UserInfo::UserAction action) {
			UserInfo::UserRights rights;

			rights.push_back("PD$ADM");

			switch (action) {
			case UserInfo::uacView:
				rights.push_back("PD$INF");
				break;

			case UserInfo::uacEdit:
				rights.push_back("PD$MOD");
				break;

			case UserInfo::uacErase:
				rights.push_back("PD$USN");
				break;

			case UserInfo::uacAdd:
				rights.push_back("PD$DOD");
				break;

			case UserInfo::uacBrowse:
				rights.push_back("PD$INF");
				rights.push_back("PD$MOD");
				rights.push_back("PD$USN");
				rights.push_back("PD$DOD");
				break;

			case UserInfo::uacPayment:
				rights.push_back("PD$KSG");
				break;
			}

			return rights;
		}
		// ------------------------------------------------------------------------------

	};

}

using namespace klienci;

UserInfo::UserStatus UserInfo::stringToUserStatus(const String& status) {
	UserStatus result = ustUndefined;

	if (!status.IsEmpty()) {
		switch (status[1]) {
		case 'A':
			result = ustActive;
			break;

		case 'B':
			result = ustBlocked;
			break;

		case 'U':
			result = ustSuspended;
			break;

		case 'Z':
			result = ustErased;
			break;
		}
	}

	return result;
}
// ------------------------------------------------------------------------------

UserInfo::UserInfo() : Ident(-1), Status(ustUndefined) {
}
// ------------------------------------------------------------------------------

bool UserInfo::isDefined() const {
	return Ident != -1;
}
// ------------------------------------------------------------------------------

bool UserInfo::checkRight(const String& right) const {
	return std::find(Rights.begin(), Rights.end(), right) != Rights.end();
}
// ------------------------------------------------------------------------------

bool UserInfo::checkRight(UserAction action, System system) const {
	UserRights rights;

	switch (system) {
	case sysBO:
		rights = UserInfoTools::buildRightsForSystemBO(action);
		break;

	case sysPD:
		rights = UserInfoTools::buildRightsForSystemPD(action);
		break;
	}

	bool has_right = false;

	for (UserRights::const_iterator it(rights.begin());
	it != rights.end(); ++it) {
		if (checkRight(*it)) {
			has_right = true;

			break;
		}
	}

	return has_right;
}
// ------------------------------------------------------------------------------
