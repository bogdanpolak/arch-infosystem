object MainForm: TMainForm
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Obs'#322'uga klient'#243'w'
  ClientHeight = 193
  ClientWidth = 271
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 8
    Top = 64
    Width = 253
    Height = 5
    Shape = bsTopLine
  end
  object Bevel2: TBevel
    Left = 8
    Top = 144
    Width = 253
    Height = 5
    Shape = bsTopLine
  end
  object btKlientDodaj: TButton
    Left = 56
    Top = 76
    Width = 157
    Height = 25
    Caption = 'Dodaj nowego klienta'
    TabOrder = 0
    OnClick = btKlientDodajClick
  end
  object btKlientAkt: TButton
    Left = 56
    Top = 108
    Width = 157
    Height = 25
    Caption = 'Aktualizuj dane klienta'
    TabOrder = 1
    OnClick = btKlientAktClick
  end
  object btKlientBaza: TButton
    Left = 56
    Top = 156
    Width = 157
    Height = 25
    Caption = 'Baza klient'#243'w'
    TabOrder = 2
    OnClick = btKlientBazaClick
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 253
    Height = 45
    Caption = ' Zalogowany operator '
    TabOrder = 3
    object stUser: TStaticText
      Left = 8
      Top = 16
      Width = 237
      Height = 17
      Hint = 'Dwukrotne klikni'#281'cie loguje operatora'
      AutoSize = False
      BorderStyle = sbsSingle
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
      OnDblClick = stUserDblClick
    end
  end
end
