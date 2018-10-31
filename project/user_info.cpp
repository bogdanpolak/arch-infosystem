//---------------------------------------------------------------------------

#pragma hdrstop

#include "user_info.h"
#include <algorithm>
//---------------------------------------------------------------------------
#pragma package(smart_init)

using namespace klienci;


UserInfo::UserStatus UserInfo::stringToUserStatus(const String& status)
{
   UserStatus result = ustUndefined;

   if(!status.IsEmpty())
   {
      switch(status[1])
      {
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
//------------------------------------------------------------------------------

UserInfo::UserInfo() : Ident(-1), Status(ustUndefined)
{
}
//------------------------------------------------------------------------------

bool UserInfo::isDefined() const
{
   return Ident != -1;
}
//------------------------------------------------------------------------------

bool UserInfo::checkRight(const String& right) const
{
   return std::find(Rights.begin(), Rights.end(), right) != Rights.end();
}
//------------------------------------------------------------------------------

bool UserInfo::checkRight(UserAction action) const
{
   UserRights rights;

   rights.push_back("BOS$ADM");

   switch(action)
   {
      case uacView:
         rights.push_back("BOS$INF");
         break;

      case uacEdit:
         rights.push_back("BOS$MOD");
         break;

      case uacErase:
         rights.push_back("BOS$USN");
         break;

      case uacAdd:
         rights.push_back("BOS$DOD");
         break;

      case uacBrowse:
         rights.push_back("BOS$INF");
         rights.push_back("BOS$MOD");
         rights.push_back("BOS$USN");
         rights.push_back("BOS$DOD");
         break;
   }

   bool has_right = false;

   for(UserRights::const_iterator it(rights.begin()); it != rights.end(); ++it)
   {
      if(checkRight(*it))
      {
         has_right = true;

         break;
      }
   }

   return has_right;
}
//------------------------------------------------------------------------------

