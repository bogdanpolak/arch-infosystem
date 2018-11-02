object MainForm: TMainForm
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Obs'#322'uga klient'#243'w'
  ClientHeight = 367
  ClientWidth = 259
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Padding.Left = 8
  Padding.Top = 8
  Padding.Right = 8
  Padding.Bottom = 8
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object gbxLogin: TGroupBox
    AlignWithMargins = True
    Left = 11
    Top = 11
    Width = 237
    Height = 142
    Align = alTop
    Caption = ' Zalogowany operator '
    Padding.Left = 4
    Padding.Top = 4
    Padding.Right = 4
    Padding.Bottom = 4
    TabOrder = 0
    object Label1: TLabel
      AlignWithMargins = True
      Left = 9
      Top = 48
      Width = 219
      Height = 26
      Align = alTop
      Alignment = taCenter
      Caption = 'kliknij podw'#243'jnie na powy'#380'sze pole, aby si'#281' zalogowa'#263
      WordWrap = True
      ExplicitWidth = 209
    end
    object Label2: TLabel
      AlignWithMargins = True
      Left = 9
      Top = 103
      Width = 219
      Height = 26
      Margins.Top = 0
      Align = alTop
      Alignment = taCenter
      Caption = 
        'admin, kierownik, pracownik, ktokolwiek, zablokowany, zawieszony' +
        ', wykre'#347'lony'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMenuHighlight
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      WordWrap = True
      ExplicitWidth = 197
    end
    object Label3: TLabel
      AlignWithMargins = True
      Left = 9
      Top = 87
      Width = 219
      Height = 13
      Margins.Top = 10
      Align = alTop
      Alignment = taCenter
      Caption = 'U'#380'ytkownicy:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMenuHighlight
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      WordWrap = True
      ExplicitWidth = 75
    end
    object stUser: TStaticText
      AlignWithMargins = True
      Left = 9
      Top = 22
      Width = 219
      Height = 20
      Hint = 'Dwukrotne klikni'#281'cie loguje operatora'
      Align = alTop
      Alignment = taCenter
      BorderStyle = sbsSingle
      Caption = '...'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
      OnDblClick = stUserDblClick
    end
  end
  object gbxCommands: TGroupBox
    Left = 8
    Top = 156
    Width = 243
    Height = 197
    Align = alTop
    Caption = 'Funkcje programu'
    Padding.Left = 4
    Padding.Top = 4
    Padding.Right = 4
    Padding.Bottom = 4
    TabOrder = 1
    object Bevel2: TBevel
      AlignWithMargins = True
      Left = 9
      Top = 142
      Width = 225
      Height = 5
      Margins.Top = 10
      Margins.Bottom = 5
      Align = alTop
      Shape = bsTopLine
      ExplicitLeft = 7
      ExplicitTop = 162
    end
    object Bevel1: TBevel
      AlignWithMargins = True
      Left = 9
      Top = 91
      Width = 225
      Height = 5
      Margins.Top = 10
      Margins.Bottom = 5
      Align = alTop
      Shape = bsTopLine
      ExplicitLeft = 0
      ExplicitTop = 144
      ExplicitWidth = 253
    end
    object btKlientAkt: TButton
      AlignWithMargins = True
      Left = 9
      Top = 53
      Width = 225
      Height = 25
      Align = alTop
      Caption = 'Aktualizuj dane klienta'
      TabOrder = 0
      OnClick = btKlientAktClick
    end
    object btKlientBaza: TButton
      AlignWithMargins = True
      Left = 9
      Top = 104
      Width = 225
      Height = 25
      Align = alTop
      Caption = 'Baza klient'#243'w'
      TabOrder = 1
      OnClick = btKlientBazaClick
    end
    object btKlientDodaj: TButton
      AlignWithMargins = True
      Left = 9
      Top = 22
      Width = 225
      Height = 25
      Align = alTop
      Caption = 'Dodaj nowego klienta'
      TabOrder = 2
      OnClick = btKlientDodajClick
    end
    object btPropertyAccount: TButton
      AlignWithMargins = True
      Left = 9
      Top = 155
      Width = 225
      Height = 25
      Align = alTop
      Caption = 'Obs'#322'uga kont podatkowych'
      TabOrder = 3
      OnClick = btPropertyAccountClick
    end
  end
  object ActionManager1: TActionManager
    Left = 184
    StyleName = 'Platform Default'
    object acAutoLogin: TAction
      Caption = 'acAutoLogin'
      ShortCut = 122
      OnExecute = acAutoLoginExecute
    end
  end
end
