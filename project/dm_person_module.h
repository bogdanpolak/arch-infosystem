//---------------------------------------------------------------------------

#ifndef dm_person_moduleH
#define dm_person_moduleH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <Datasnap.DBClient.hpp>
#include <Datasnap.Provider.hpp>
//---------------------------------------------------------------------------

/*
* Modu³ danych do obs³ugi osób fizycznych.
*
* Odczyt i zapis danych odbywa siê przy u¿yciu jawnych i niezagnie¿d¿onych transakcji (przy domyœlnych
* transakcjach zmiany by³y widoczne dopiero po zamkniêciu aplikacji).
*/

class TPersonModule : public TDataModule
{
__published:	// IDE-managed Components
   TFDQuery *quPerson;
   TFDQuery *quAddress;
   TDataSource *dsPerson2Address;
   TDataSetProvider *dspPerson;
   TClientDataSet *cdsPerson;
   TClientDataSet *cdsAddress;
   TFDTransaction *trPerson;
   TFDStoredProc *spPersonID;
   TFDCommand *quCommand;
   TFDStoredProc *spAddressID;
   TIntegerField *quPersonID_OSOBY;
   TStringField *quPersonIMIE;
   TStringField *quPersonIMIE_DRUGIE;
   TStringField *quPersonNAZWISKO;
   TStringField *quPersonIMIE_OJCA;
   TStringField *quPersonIMIE_MATKI;
   TStringField *quPersonPESEL;
   TStringField *quPersonTYP_DOK_TOZ;
   TStringField *quPersonNR_DOK_TOZ;
   TSQLTimeStampField *quPersonDATA_UR;
   TStringField *quPersonMIEJSCE_UR;
   TStringField *quPersonRODZAJ_OSB;
   TStringField *quPersonNAZWA;
   TStringField *quPersonNIP;
   TStringField *quPersonKOD_KRAJU;
   TStringField *quPersonREGON;
   TStringField *quPersonEMAIL;
   TStringField *quPersonTELEFON;
   TStringField *quPersonRB_NUMER;
   TSQLTimeStampField *quPersonREJ_DATA;
   TIntegerField *quPersonREJ_OPER;
   TSQLTimeStampField *quPersonMOD_DATA;
   TIntegerField *quPersonMOD_OPER;
   TIntegerField *cdsPersonID_OSOBY;
   TStringField *cdsPersonIMIE;
   TStringField *cdsPersonIMIE_DRUGIE;
   TStringField *cdsPersonNAZWISKO;
   TStringField *cdsPersonIMIE_OJCA;
   TStringField *cdsPersonIMIE_MATKI;
   TStringField *cdsPersonPESEL;
   TStringField *cdsPersonTYP_DOK_TOZ;
   TStringField *cdsPersonNR_DOK_TOZ;
   TSQLTimeStampField *cdsPersonDATA_UR;
   TStringField *cdsPersonMIEJSCE_UR;
   TStringField *cdsPersonRODZAJ_OSB;
   TStringField *cdsPersonNAZWA;
   TStringField *cdsPersonNIP;
   TStringField *cdsPersonKOD_KRAJU;
   TStringField *cdsPersonREGON;
   TStringField *cdsPersonEMAIL;
   TStringField *cdsPersonTELEFON;
   TStringField *cdsPersonRB_NUMER;
   TSQLTimeStampField *cdsPersonREJ_DATA;
   TIntegerField *cdsPersonREJ_OPER;
   TSQLTimeStampField *cdsPersonMOD_DATA;
   TIntegerField *cdsPersonMOD_OPER;
   TDataSetField *cdsPersonquAddress;
   void __fastcall dspPersonBeforeUpdateRecord(TObject *Sender, TDataSet *SourceDS, TCustomClientDataSet *DeltaDS,
          TUpdateKind UpdateKind, bool &Applied);
   void __fastcall cdsAddressAfterInsert(TDataSet *DataSet);
   void __fastcall cdsPersonAfterInsert(TDataSet *DataSet);
   void __fastcall dspPersonBeforeApplyUpdates(TObject *Sender, OleVariant &OwnerData);
   void __fastcall dspPersonUpdateError(TObject *Sender, TCustomClientDataSet *DataSet, EUpdateError *E,
          TUpdateKind UpdateKind, TResolverResponse &Response);
   void __fastcall cdsAddressBeforePost(TDataSet *DataSet);
private:	// User declarations
   String m_updateError;
   int    m_personID;     // identyfikator osoby fizycznej; przechowywany w obiekcie ze wzglêdu na zapytanie uruchamiane podczas usuniêcia osoby

public:		// User declarations
   __fastcall TPersonModule(TComponent* Owner);


   int __fastcall GetPersonID();

   bool __fastcall IsEditing();

   void __fastcall Open(int person_id);

   void __fastcall Append();

   void __fastcall Edit();

   void __fastcall Erase();

   void __fastcall Post();

   void __fastcall Cancel();

   void __fastcall Close();

   void __fastcall ApplyUpdates();

   void __fastcall CancelUpdates();

};
//---------------------------------------------------------------------------
extern PACKAGE TPersonModule *PersonModule;
//---------------------------------------------------------------------------
#endif
