object BrowserDlg: TBrowserDlg
  Left = 0
  Top = 0
  Caption = 'Przegl'#261'danie bazy klient'#243'w'
  ClientHeight = 610
  ClientWidth = 930
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
    Width = 930
    Height = 569
    Align = alClient
    TabOrder = 0
    ExplicitLeft = 532
    ExplicitTop = 120
    ExplicitWidth = 185
    ExplicitHeight = 41
    object DBGrid1: TDBGrid
      Left = 1
      Top = 1
      Width = 928
      Height = 567
      Align = alClient
      DataSource = DataSource1
      DrawingStyle = gdsGradient
      Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgAlwaysShowSelection, dgTitleClick, dgTitleHotTrack]
      TabOrder = 0
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'Tahoma'
      TitleFont.Style = []
      OnDblClick = btInfoClick
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 569
    Width = 930
    Height = 41
    Align = alBottom
    TabOrder = 1
    ExplicitLeft = 412
    ExplicitTop = 384
    ExplicitWidth = 185
    DesignSize = (
      930
      41)
    object DBNavigator1: TDBNavigator
      Left = 8
      Top = 8
      Width = 128
      Height = 25
      DataSource = DataSource1
      VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast]
      TabOrder = 0
    end
    object btInfo: TButton
      Left = 176
      Top = 8
      Width = 77
      Height = 25
      Caption = 'Wy'#347'wietl'
      TabOrder = 1
      OnClick = btInfoClick
    end
    object btEdit: TButton
      Left = 336
      Top = 8
      Width = 77
      Height = 25
      Caption = 'Edytuj'
      TabOrder = 2
      OnClick = btEditClick
    end
    object btErase: TButton
      Left = 416
      Top = 8
      Width = 77
      Height = 25
      Caption = 'Usu'#324
      TabOrder = 3
      OnClick = btEraseClick
    end
    object Button4: TButton
      Left = 844
      Top = 8
      Width = 77
      Height = 25
      Anchors = [akTop, akRight]
      Caption = 'Zamknij'
      ModalResult = 8
      TabOrder = 4
    end
    object btAppend: TButton
      Left = 256
      Top = 8
      Width = 77
      Height = 25
      Caption = 'Dodaj'
      TabOrder = 5
      OnClick = btAppendClick
    end
  end
  object DataSource1: TDataSource
    AutoEdit = False
    DataSet = FDQuery1
    Left = 100
    Top = 144
  end
  object FDQuery1: TFDQuery
    Connection = DatabaseModule.ConnectionDB
    SQL.Strings = (
      'select * from bo_main m '
      'inner join bo_adres a on (a.id_osoby = m.id_osoby)'
      'order by m.nazwa, a.miasto, a.ulica, a.dom, a.lokal')
    Left = 208
    Top = 144
  end
end
