object DatabaseModule: TDatabaseModule
  OldCreateOrder = False
  Height = 283
  Width = 285
  object ConnectionDB: TFDConnection
    Params.Strings = (
      'Database=C:\dane\infosys_groszek\klienci.fdb'
      'User_Name=sysdba'
      'Password=masterkey'
      'SQLDialect=1'
      'CharacterSet=UTF8'
      'DriverID=FB')
    FetchOptions.AssignedValues = [evAutoFetchAll]
    ResourceOptions.AssignedValues = [rvStoreItems, rvAutoConnect]
    ResourceOptions.StoreItems = [siMeta, siDelta]
    Connected = True
    LoginPrompt = False
    Left = 52
    Top = 28
  end
  object UserData: TFDQuery
    Connection = ConnectionDB
    ResourceOptions.AssignedValues = [rvStoreItems]
    SQL.Strings = (
      'select * from op_oper'
      'where upper(nazwa) = upper(:NAZWA) and haslo = :HASLO')
    Left = 52
    Top = 92
    ParamData = <
      item
        Name = 'NAZWA'
        DataType = ftString
        ParamType = ptInput
        Size = 30
      end
      item
        Name = 'HASLO'
        DataType = ftString
        ParamType = ptInput
        Size = 30
      end>
  end
  object UserRights: TFDQuery
    Connection = ConnectionDB
    SQL.Strings = (
      'select * from op_opfun'
      'where id_oper = :ID_OPER')
    Left = 128
    Top = 92
    ParamData = <
      item
        Name = 'ID_OPER'
        ParamType = ptInput
      end>
  end
  object SelectData: TFDQuery
    Connection = ConnectionDB
    Left = 52
    Top = 156
  end
end
