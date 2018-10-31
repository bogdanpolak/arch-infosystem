object PersonModule: TPersonModule
  OldCreateOrder = False
  Height = 277
  Width = 411
  object quPerson: TFDQuery
    Connection = DatabaseModule.ConnectionDB
    Transaction = trPerson
    FetchOptions.AssignedValues = [evUnidirectional]
    SQL.Strings = (
      
        'select f.*, m.rodzaj_osb, m.nazwa, m.nip, m.kod_kraju, m.regon, ' +
        'm.email, m.telefon, m.rb_numer, m.rej_data, m.rej_oper, m.mod_da' +
        'ta, m.mod_oper from bo_fiz f'
      'inner join bo_main m on (m.id_osoby = f.id_osoby)'
      'where f.id_osoby = :ID_OSOBY')
    Left = 32
    Top = 72
    ParamData = <
      item
        Name = 'ID_OSOBY'
        DataType = ftInteger
        ParamType = ptInput
      end>
    object quPersonID_OSOBY: TIntegerField
      FieldName = 'ID_OSOBY'
      Origin = 'ID_OSOBY'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      Required = True
    end
    object quPersonIMIE: TStringField
      FieldName = 'IMIE'
      Origin = 'IMIE'
      Size = 30
    end
    object quPersonIMIE_DRUGIE: TStringField
      FieldName = 'IMIE_DRUGIE'
      Origin = 'IMIE_DRUGIE'
      Size = 30
    end
    object quPersonNAZWISKO: TStringField
      FieldName = 'NAZWISKO'
      Origin = 'NAZWISKO'
      Size = 50
    end
    object quPersonIMIE_OJCA: TStringField
      FieldName = 'IMIE_OJCA'
      Origin = 'IMIE_OJCA'
      Size = 30
    end
    object quPersonIMIE_MATKI: TStringField
      FieldName = 'IMIE_MATKI'
      Origin = 'IMIE_MATKI'
      Size = 30
    end
    object quPersonPESEL: TStringField
      FieldName = 'PESEL'
      Origin = 'PESEL'
      Size = 11
    end
    object quPersonTYP_DOK_TOZ: TStringField
      FieldName = 'TYP_DOK_TOZ'
      Origin = 'TYP_DOK_TOZ'
      FixedChar = True
      Size = 1
    end
    object quPersonNR_DOK_TOZ: TStringField
      FieldName = 'NR_DOK_TOZ'
      Origin = 'NR_DOK_TOZ'
      Size = 10
    end
    object quPersonDATA_UR: TSQLTimeStampField
      FieldName = 'DATA_UR'
      Origin = 'DATA_UR'
    end
    object quPersonMIEJSCE_UR: TStringField
      FieldName = 'MIEJSCE_UR'
      Origin = 'MIEJSCE_UR'
      Size = 65
    end
    object quPersonRODZAJ_OSB: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'RODZAJ_OSB'
      Origin = 'RODZAJ_OSB'
      ProviderFlags = []
      FixedChar = True
      Size = 1
    end
    object quPersonNAZWA: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'NAZWA'
      Origin = 'NAZWA'
      ProviderFlags = []
      Size = 80
    end
    object quPersonNIP: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'NIP'
      Origin = 'NIP'
      ProviderFlags = []
      Size = 13
    end
    object quPersonKOD_KRAJU: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'KOD_KRAJU'
      Origin = 'KOD_KRAJU'
      ProviderFlags = []
      FixedChar = True
      Size = 2
    end
    object quPersonREGON: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'REGON'
      Origin = 'REGON'
      ProviderFlags = []
      Size = 15
    end
    object quPersonEMAIL: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'EMAIL'
      Origin = 'EMAIL'
      ProviderFlags = []
      Size = 40
    end
    object quPersonTELEFON: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'TELEFON'
      Origin = 'TELEFON'
      ProviderFlags = []
    end
    object quPersonRB_NUMER: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'RB_NUMER'
      Origin = 'RB_NUMER'
      ProviderFlags = []
      Size = 40
    end
    object quPersonREJ_DATA: TSQLTimeStampField
      AutoGenerateValue = arDefault
      FieldName = 'REJ_DATA'
      Origin = 'REJ_DATA'
      ProviderFlags = []
    end
    object quPersonREJ_OPER: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'REJ_OPER'
      Origin = 'REJ_OPER'
      ProviderFlags = []
    end
    object quPersonMOD_DATA: TSQLTimeStampField
      AutoGenerateValue = arDefault
      FieldName = 'MOD_DATA'
      Origin = 'MOD_DATA'
      ProviderFlags = []
    end
    object quPersonMOD_OPER: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'MOD_OPER'
      Origin = 'MOD_OPER'
      ProviderFlags = []
    end
  end
  object quAddress: TFDQuery
    MasterSource = dsPerson2Address
    MasterFields = 'ID_OSOBY'
    DetailFields = 'ID_OSOBY'
    Connection = DatabaseModule.ConnectionDB
    Transaction = trPerson
    FetchOptions.AssignedValues = [evCache, evUnidirectional]
    FetchOptions.Cache = [fiBlobs, fiMeta]
    SQL.Strings = (
      'select * from bo_adres'
      'where id_osoby = :ID_OSOBY')
    Left = 212
    Top = 72
    ParamData = <
      item
        Name = 'ID_OSOBY'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end>
  end
  object dsPerson2Address: TDataSource
    AutoEdit = False
    DataSet = quPerson
    Left = 120
    Top = 72
  end
  object dspPerson: TDataSetProvider
    DataSet = quPerson
    Options = [poCascadeDeletes, poCascadeUpdates, poUseQuoteChar]
    UpdateMode = upWhereKeyOnly
    OnUpdateError = dspPersonUpdateError
    BeforeUpdateRecord = dspPersonBeforeUpdateRecord
    BeforeApplyUpdates = dspPersonBeforeApplyUpdates
    Left = 32
    Top = 152
  end
  object cdsPerson: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'dspPerson'
    AfterInsert = cdsPersonAfterInsert
    Left = 32
    Top = 212
    object cdsPersonID_OSOBY: TIntegerField
      FieldName = 'ID_OSOBY'
      Origin = 'ID_OSOBY'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      Required = True
    end
    object cdsPersonIMIE: TStringField
      FieldName = 'IMIE'
      Origin = 'IMIE'
      Size = 30
    end
    object cdsPersonIMIE_DRUGIE: TStringField
      FieldName = 'IMIE_DRUGIE'
      Origin = 'IMIE_DRUGIE'
      Size = 30
    end
    object cdsPersonNAZWISKO: TStringField
      FieldName = 'NAZWISKO'
      Origin = 'NAZWISKO'
      Size = 50
    end
    object cdsPersonIMIE_OJCA: TStringField
      FieldName = 'IMIE_OJCA'
      Origin = 'IMIE_OJCA'
      Size = 30
    end
    object cdsPersonIMIE_MATKI: TStringField
      FieldName = 'IMIE_MATKI'
      Origin = 'IMIE_MATKI'
      Size = 30
    end
    object cdsPersonPESEL: TStringField
      FieldName = 'PESEL'
      Origin = 'PESEL'
      Size = 11
    end
    object cdsPersonTYP_DOK_TOZ: TStringField
      FieldName = 'TYP_DOK_TOZ'
      Origin = 'TYP_DOK_TOZ'
      FixedChar = True
      Size = 1
    end
    object cdsPersonNR_DOK_TOZ: TStringField
      FieldName = 'NR_DOK_TOZ'
      Origin = 'NR_DOK_TOZ'
      Size = 10
    end
    object cdsPersonDATA_UR: TSQLTimeStampField
      FieldName = 'DATA_UR'
      Origin = 'DATA_UR'
    end
    object cdsPersonMIEJSCE_UR: TStringField
      FieldName = 'MIEJSCE_UR'
      Origin = 'MIEJSCE_UR'
      Size = 65
    end
    object cdsPersonRODZAJ_OSB: TStringField
      FieldName = 'RODZAJ_OSB'
      Origin = 'RODZAJ_OSB'
      ProviderFlags = []
      FixedChar = True
      Size = 1
    end
    object cdsPersonNAZWA: TStringField
      FieldName = 'NAZWA'
      Origin = 'NAZWA'
      ProviderFlags = []
      Size = 80
    end
    object cdsPersonNIP: TStringField
      FieldName = 'NIP'
      Origin = 'NIP'
      ProviderFlags = []
      Size = 13
    end
    object cdsPersonKOD_KRAJU: TStringField
      FieldName = 'KOD_KRAJU'
      Origin = 'KOD_KRAJU'
      ProviderFlags = []
      FixedChar = True
      Size = 2
    end
    object cdsPersonREGON: TStringField
      FieldName = 'REGON'
      Origin = 'REGON'
      ProviderFlags = []
      Size = 15
    end
    object cdsPersonEMAIL: TStringField
      FieldName = 'EMAIL'
      Origin = 'EMAIL'
      ProviderFlags = []
      Size = 40
    end
    object cdsPersonTELEFON: TStringField
      FieldName = 'TELEFON'
      Origin = 'TELEFON'
      ProviderFlags = []
    end
    object cdsPersonRB_NUMER: TStringField
      FieldName = 'RB_NUMER'
      Origin = 'RB_NUMER'
      ProviderFlags = []
      Size = 40
    end
    object cdsPersonREJ_DATA: TSQLTimeStampField
      FieldName = 'REJ_DATA'
      Origin = 'REJ_DATA'
      ProviderFlags = []
    end
    object cdsPersonREJ_OPER: TIntegerField
      FieldName = 'REJ_OPER'
      Origin = 'REJ_OPER'
      ProviderFlags = []
    end
    object cdsPersonMOD_DATA: TSQLTimeStampField
      FieldName = 'MOD_DATA'
      Origin = 'MOD_DATA'
      ProviderFlags = []
    end
    object cdsPersonMOD_OPER: TIntegerField
      FieldName = 'MOD_OPER'
      Origin = 'MOD_OPER'
      ProviderFlags = []
    end
    object cdsPersonquAddress: TDataSetField
      FieldName = 'quAddress'
    end
  end
  object cdsAddress: TClientDataSet
    Aggregates = <>
    DataSetField = cdsPersonquAddress
    Params = <>
    AfterInsert = cdsAddressAfterInsert
    BeforePost = cdsAddressBeforePost
    Left = 104
    Top = 212
  end
  object trPerson: TFDTransaction
    Options.EnableNested = False
    Connection = DatabaseModule.ConnectionDB
    Left = 32
    Top = 12
  end
  object spPersonID: TFDStoredProc
    Connection = DatabaseModule.ConnectionDB
    Transaction = trPerson
    StoredProcName = 'BO_SP_MAIN_GEN_ID'
    Left = 128
    Top = 12
  end
  object quCommand: TFDCommand
    Connection = DatabaseModule.ConnectionDB
    Transaction = trPerson
    Left = 304
    Top = 72
  end
  object spAddressID: TFDStoredProc
    Connection = DatabaseModule.ConnectionDB
    Transaction = trPerson
    StoredProcName = 'BO_SP_ADRES_GEN_ID'
    Left = 200
    Top = 12
  end
end
