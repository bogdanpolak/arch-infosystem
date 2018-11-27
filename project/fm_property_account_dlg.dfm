object PropertyAccount: TPropertyAccount
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Konto podatku od nieruchomo'#347'ci'
  ClientHeight = 500
  ClientWidth = 761
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 761
    Height = 161
    Align = alTop
    TabOrder = 0
    object DBGrid1: TDBGrid
      Left = 1
      Top = 1
      Width = 759
      Height = 159
      Align = alClient
      DataSource = DataSource1
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
    Top = 161
    Width = 761
    Height = 298
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 1
    object PageControl1: TPageControl
      Left = 0
      Top = 0
      Width = 761
      Height = 298
      ActivePage = TabSheet1
      Align = alClient
      TabOrder = 0
      object TabSheet1: TTabSheet
        Caption = 'Sk'#322'adniki'
        object Panel4: TPanel
          Left = 0
          Top = 0
          Width = 753
          Height = 270
          Align = alClient
          Caption = 
            'Lista sk'#322'adnik'#243'w nieruchomo'#347'ci do obliczenia podatku (tabela PD_' +
            'SKLADNIKI)'
          ParentBackground = False
          TabOrder = 0
        end
      end
      object TabSheet2: TTabSheet
        Caption = 'Podatnicy'
        ImageIndex = 1
        object Panel5: TPanel
          Left = 0
          Top = 0
          Width = 753
          Height = 270
          Align = alClient
          Caption = 'Lista podatnik'#243'w podatku od nieruchomo'#347'ci (tabela PD_PODATNICY)'
          ParentBackground = False
          TabOrder = 0
        end
      end
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 459
    Width = 761
    Height = 41
    Align = alBottom
    TabOrder = 2
    object btCancel: TButton
      Left = 8
      Top = 8
      Width = 77
      Height = 25
      TabOrder = 0
    end
    object btSave: TButton
      Left = 676
      Top = 8
      Width = 77
      Height = 25
      TabOrder = 1
    end
  end
  object FDQuery1: TFDQuery
    Active = True
    Connection = DatabaseModule.ConnectionDB
    SQL.Strings = (
      'SELECT * FROM PD_KONTA')
    Left = 448
    Top = 256
  end
  object DataSource1: TDataSource
    DataSet = FDQuery1
    Left = 388
    Top = 249
  end
end
