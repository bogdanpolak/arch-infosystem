//---------------------------------------------------------------------------

#ifndef user_infoH
#define user_infoH
//---------------------------------------------------------------------------
#include <System.hpp>
#include <vector>
//---------------------------------------------------------------------------

namespace klienci
{

class UserInfo
{
public:

   enum UserStatus
   {
      ustActive    = 'A',  // operator czynny
      ustBlocked   = 'B',  // operator zablokowany (kilka prób nieudanego zalogowania)
      ustSuspended = 'U',  // operator zwieszony (dzia³anie administratora)
      ustErased    = 'Z',  // operator wykreœlony
      ustUndefined = '?'
   };


   // Rodzaj czynnoœci do wykonania
   enum UserAction
   {
      uacView,   // tylko podgl¹d danych klienta
      uacEdit,   // edycja i podgl¹d danych klienta
      uacErase,  // usuwanie i podgl¹d danych klienta
      uacAdd,    // dodawanie nowego klienta i podgl¹d danych klienta
      uacBrowse  // przegl¹danie danych klienta
   };


   static UserStatus stringToUserStatus(const String& status);


   typedef std::vector<String> UserRights;


   int        Ident;
   String     Name;
   String     Password;
   String     Forename;
   String     Surname;
   UserStatus Status;
   UserRights Rights;


   UserInfo();


   bool isDefined() const;

   bool checkRight(const String& right) const;

   bool checkRight(UserAction action) const;

};

} // namespace klienci

#endif
