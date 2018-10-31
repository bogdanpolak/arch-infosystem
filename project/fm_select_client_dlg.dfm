object SelectClientDlg: TSelectClientDlg
  Left = 0
  Top = 0
  Caption = 'Wyb'#243'r klienta'
  ClientHeight = 375
  ClientWidth = 697
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 697
    Height = 334
    Align = alClient
    TabOrder = 0
    ExplicitLeft = 424
    ExplicitTop = 96
    ExplicitWidth = 185
    ExplicitHeight = 41
    object DBGrid1: TDBGrid
      Left = 1
      Top = 1
      Width = 695
      Height = 332
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
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 334
    Width = 697
    Height = 41
    Align = alBottom
    TabOrder = 1
    ExplicitLeft = 288
    ExplicitTop = 196
    ExplicitWidth = 185
    DesignSize = (
      697
      41)
    object Button1: TButton
      Left = 612
      Top = 8
      Width = 77
      Height = 25
      Anchors = [akTop, akRight]
      Caption = 'Wybierz'
      ModalResult = 1
      TabOrder = 0
    end
    object Button2: TButton
      Left = 8
      Top = 8
      Width = 77
      Height = 25
      Caption = 'Anuluj'
      ModalResult = 2
      TabOrder = 1
    end
  end
  object DataSource1: TDataSource
    AutoEdit = False
    Left = 208
    Top = 128
  end
end
