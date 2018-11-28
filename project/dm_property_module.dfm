object PropertyModule: TPropertyModule
  OldCreateOrder = False
  Height = 429
  Width = 572
  object quKonta: TFDQuery
    Connection = DatabaseModule.ConnectionDB
    SQL.Strings = (
      '')
    Left = 56
    Top = 16
  end
  object quSkladniki: TFDQuery
    MasterSource = dsKonta
    MasterFields = 'ID_KONTA'
    Connection = DatabaseModule.ConnectionDB
    FetchOptions.AssignedValues = [evCache]
    FetchOptions.Cache = [fiBlobs, fiMeta]
    SQL.Strings = (
      '')
    Left = 24
    Top = 112
  end
  object dsKonta: TDataSource
    AutoEdit = False
    DataSet = quKonta
    Left = 58
    Top = 65
  end
  object quPodatnicy: TFDQuery
    MasterSource = dsKonta
    MasterFields = 'ID_KONTA'
    Connection = DatabaseModule.ConnectionDB
    FetchOptions.AssignedValues = [evCache]
    FetchOptions.Cache = [fiBlobs, fiMeta]
    Left = 88
    Top = 113
  end
end
