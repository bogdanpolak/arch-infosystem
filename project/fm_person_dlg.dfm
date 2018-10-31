object PersonDlg: TPersonDlg
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  ClientHeight = 505
  ClientWidth = 612
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  OnCloseQuery = FormCloseQuery
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 612
    Height = 173
    Align = alTop
    TabOrder = 0
    object Label1: TLabel
      Left = 8
      Top = 8
      Width = 20
      Height = 13
      Caption = 'Imi'#281
    end
    object Label2: TLabel
      Left = 100
      Top = 8
      Width = 44
      Height = 13
      Caption = 'Nazwisko'
    end
    object Label3: TLabel
      Left = 236
      Top = 8
      Width = 52
      Height = 13
      Caption = 'Drugie imi'#281
    end
    object Label4: TLabel
      Left = 328
      Top = 8
      Width = 43
      Height = 13
      Caption = 'Imi'#281' ojca'
    end
    object Label5: TLabel
      Left = 420
      Top = 8
      Width = 48
      Height = 13
      Caption = 'Imi'#281' matki'
    end
    object Label6: TLabel
      Left = 512
      Top = 8
      Width = 29
      Height = 13
      Caption = 'PESEL'
    end
    object Label7: TLabel
      Left = 8
      Top = 52
      Width = 59
      Height = 13
      Caption = 'Adres e-mail'
    end
    object Label8: TLabel
      Left = 172
      Top = 52
      Width = 74
      Height = 13
      Caption = 'Numer telefonu'
    end
    object Label9: TLabel
      Left = 328
      Top = 52
      Width = 73
      Height = 13
      Caption = 'Data urodzenia'
    end
    object Label10: TLabel
      Left = 420
      Top = 52
      Width = 85
      Height = 13
      Caption = 'Miejsce urodzenia'
    end
    object DBEdit1: TDBEdit
      Left = 8
      Top = 24
      Width = 89
      Height = 21
      DataField = 'IMIE'
      DataSource = dsPerson
      TabOrder = 0
    end
    object DBEdit2: TDBEdit
      Left = 100
      Top = 24
      Width = 133
      Height = 21
      DataField = 'NAZWISKO'
      DataSource = dsPerson
      TabOrder = 1
    end
    object DBEdit3: TDBEdit
      Left = 236
      Top = 24
      Width = 89
      Height = 21
      DataField = 'IMIE_DRUGIE'
      DataSource = dsPerson
      TabOrder = 2
    end
    object DBEdit4: TDBEdit
      Left = 328
      Top = 24
      Width = 89
      Height = 21
      DataField = 'IMIE_OJCA'
      DataSource = dsPerson
      TabOrder = 3
    end
    object DBEdit5: TDBEdit
      Left = 420
      Top = 24
      Width = 89
      Height = 21
      DataField = 'IMIE_MATKI'
      DataSource = dsPerson
      TabOrder = 4
    end
    object DBEdit6: TDBEdit
      Left = 512
      Top = 24
      Width = 89
      Height = 21
      DataField = 'PESEL'
      DataSource = dsPerson
      TabOrder = 5
    end
    object DBEdit7: TDBEdit
      Left = 8
      Top = 68
      Width = 161
      Height = 21
      DataField = 'EMAIL'
      DataSource = dsPerson
      TabOrder = 6
    end
    object DBEdit8: TDBEdit
      Left = 172
      Top = 68
      Width = 153
      Height = 21
      DataField = 'TELEFON'
      DataSource = dsPerson
      TabOrder = 7
    end
    object DBEdit9: TDBEdit
      Left = 328
      Top = 68
      Width = 89
      Height = 21
      DataField = 'DATA_UR'
      DataSource = dsPerson
      TabOrder = 8
    end
    object DBEdit10: TDBEdit
      Left = 420
      Top = 68
      Width = 181
      Height = 21
      DataField = 'MIEJSCE_UR'
      DataSource = dsPerson
      TabOrder = 9
    end
    object GroupBox1: TGroupBox
      Left = 8
      Top = 96
      Width = 317
      Height = 65
      Caption = ' Dokument to'#380'samo'#347'ci '
      TabOrder = 10
      object Label11: TLabel
        Left = 8
        Top = 16
        Width = 33
        Height = 13
        Caption = 'Rodzaj'
      end
      object Label12: TLabel
        Left = 156
        Top = 16
        Width = 31
        Height = 13
        Caption = 'Numer'
      end
      object DBEdit11: TDBEdit
        Left = 156
        Top = 32
        Width = 153
        Height = 21
        DataField = 'NR_DOK_TOZ'
        DataSource = dsPerson
        TabOrder = 1
      end
      object cbRodzajDok: TComboBox
        Left = 8
        Top = 32
        Width = 145
        Height = 21
        Style = csDropDownList
        TabOrder = 0
        Items.Strings = (
          'Dow'#243'd osobisty (D)'
          'Prawo jazdy (J)'
          'Paszport (P)')
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 173
    Width = 612
    Height = 291
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 1
    object Panel4: TPanel
      Left = 0
      Top = 0
      Width = 612
      Height = 21
      Align = alTop
      Caption = 'Lista adres'#243'w'
      Color = clInactiveCaption
      ParentBackground = False
      TabOrder = 0
    end
    object Panel5: TPanel
      Left = 0
      Top = 21
      Width = 612
      Height = 168
      Align = alClient
      BevelOuter = bvNone
      TabOrder = 1
      object Panel7: TPanel
        Left = 0
        Top = 0
        Width = 612
        Height = 127
        Align = alClient
        TabOrder = 0
        object DBGrid1: TDBGrid
          Left = 1
          Top = 1
          Width = 610
          Height = 125
          Align = alClient
          DataSource = dsAddress
          DrawingStyle = gdsGradient
          Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgAlwaysShowSelection, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
          TabOrder = 0
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -11
          TitleFont.Name = 'Tahoma'
          TitleFont.Style = []
          Columns = <
            item
              Expanded = False
              FieldName = 'MIASTO'
              Title.Alignment = taCenter
              Title.Caption = 'Miejscowo'#347#263
              Width = 193
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'ULICA'
              Title.Alignment = taCenter
              Title.Caption = 'Ulica'
              Width = 218
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'DOM'
              Title.Alignment = taCenter
              Title.Caption = 'Dom'
              Width = 65
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'LOKAL'
              Title.Alignment = taCenter
              Title.Caption = 'Lokal'
              Width = 44
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'KOD'
              Title.Alignment = taCenter
              Title.Caption = 'Kod'
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'POCZTA'
              Title.Alignment = taCenter
              Title.Caption = 'Poczta'
              Width = 203
              Visible = True
            end>
        end
      end
      object Panel8: TPanel
        Left = 0
        Top = 127
        Width = 612
        Height = 41
        Align = alBottom
        TabOrder = 1
        object dnaNavigator: TDBNavigator
          Left = 8
          Top = 8
          Width = 216
          Height = 25
          DataSource = dsAddress
          VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast, nbInsert, nbDelete, nbEdit, nbPost, nbCancel]
          TabOrder = 0
        end
      end
    end
    object Panel6: TPanel
      Left = 0
      Top = 189
      Width = 612
      Height = 102
      Align = alBottom
      TabOrder = 2
      object Label13: TLabel
        Left = 8
        Top = 8
        Width = 59
        Height = 13
        Caption = 'Miejscowo'#347#263
      end
      object Label14: TLabel
        Left = 232
        Top = 8
        Width = 22
        Height = 13
        Caption = 'Ulica'
      end
      object Label15: TLabel
        Left = 420
        Top = 8
        Width = 21
        Height = 13
        Caption = 'Dom'
      end
      object Label16: TLabel
        Left = 476
        Top = 8
        Width = 24
        Height = 13
        Caption = 'Lokal'
      end
      object Label17: TLabel
        Left = 160
        Top = 8
        Width = 33
        Height = 13
        Caption = 'Typ ul.'
      end
      object Label18: TLabel
        Left = 8
        Top = 52
        Width = 18
        Height = 13
        Caption = 'Kod'
      end
      object Label19: TLabel
        Left = 56
        Top = 52
        Width = 32
        Height = 13
        Caption = 'Poczta'
      end
      object Label20: TLabel
        Left = 232
        Top = 52
        Width = 69
        Height = 13
        Caption = 'Rodzaj adresu'
      end
      object DBEdit12: TDBEdit
        Left = 8
        Top = 24
        Width = 149
        Height = 21
        DataField = 'MIASTO'
        DataSource = dsAddress
        TabOrder = 0
      end
      object DBEdit13: TDBEdit
        Left = 232
        Top = 24
        Width = 185
        Height = 21
        DataField = 'ULICA'
        DataSource = dsAddress
        TabOrder = 2
      end
      object DBEdit14: TDBEdit
        Left = 420
        Top = 24
        Width = 53
        Height = 21
        DataField = 'DOM'
        DataSource = dsAddress
        TabOrder = 3
      end
      object DBEdit15: TDBEdit
        Left = 476
        Top = 24
        Width = 41
        Height = 21
        DataField = 'LOKAL'
        DataSource = dsAddress
        TabOrder = 4
      end
      object DBEdit16: TDBEdit
        Left = 8
        Top = 68
        Width = 45
        Height = 21
        DataField = 'KOD'
        DataSource = dsAddress
        TabOrder = 5
      end
      object DBComboBox1: TDBComboBox
        Left = 160
        Top = 24
        Width = 69
        Height = 21
        DataField = 'TYP_ULICY'
        DataSource = dsAddress
        Items.Strings = (
          'ul.'
          'al.'
          'plac')
        TabOrder = 1
      end
      object DBEdit17: TDBEdit
        Left = 56
        Top = 68
        Width = 173
        Height = 21
        DataField = 'POCZTA'
        DataSource = dsAddress
        TabOrder = 6
      end
      object cbRodzajAdr: TComboBox
        Left = 232
        Top = 68
        Width = 185
        Height = 21
        Style = csDropDownList
        TabOrder = 7
        Items.Strings = (
          'Zamieszkania (M)'
          'Zameldowania (Z)'
          'Siedziby (S)'
          'Inny (I)')
      end
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 464
    Width = 612
    Height = 41
    Align = alBottom
    TabOrder = 2
    object btSave: TButton
      Left = 528
      Top = 8
      Width = 77
      Height = 25
      TabOrder = 0
    end
    object btCancel: TButton
      Left = 8
      Top = 8
      Width = 77
      Height = 25
      Action = aciCancel
      TabOrder = 1
    end
  end
  object dsPerson: TDataSource
    AutoEdit = False
    DataSet = PersonModule.cdsPerson
    OnUpdateData = dsPersonUpdateData
    Left = 348
    Top = 108
  end
  object dsAddress: TDataSource
    AutoEdit = False
    DataSet = PersonModule.cdsAddress
    OnDataChange = dsAddressDataChange
    OnUpdateData = dsAddressUpdateData
    Left = 420
    Top = 109
  end
  object ActionList1: TActionList
    Left = 500
    Top = 112
    object aciCancel: TAction
      Caption = 'Anuluj'
      OnExecute = aciCancelExecute
    end
    object aciSave: TAction
      Caption = 'Zapisz'
      OnExecute = aciSaveExecute
    end
    object aciClose: TAction
      Caption = 'Zamknij'
      OnExecute = aciCloseExecute
    end
  end
end
