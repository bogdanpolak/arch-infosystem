object LoginDlg: TLoginDlg
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Logowanie'
  ClientHeight = 111
  ClientWidth = 331
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
  object Label1: TLabel
    Left = 24
    Top = 16
    Width = 44
    Height = 13
    Caption = 'Operator'
  end
  object Label2: TLabel
    Left = 28
    Top = 44
    Width = 27
    Height = 13
    Caption = 'Has'#322'o'
  end
  object edUser: TEdit
    Left = 76
    Top = 12
    Width = 145
    Height = 21
    TabOrder = 1
  end
  object edPassw: TEdit
    Left = 76
    Top = 40
    Width = 145
    Height = 21
    PasswordChar = '*'
    TabOrder = 2
  end
  object btLogin: TButton
    Left = 240
    Top = 78
    Width = 75
    Height = 25
    Caption = 'Gotowe'
    Default = True
    TabOrder = 3
    OnClick = btLoginClick
  end
  object btCancel: TButton
    Left = 8
    Top = 76
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Anuluj'
    ModalResult = 2
    TabOrder = 4
  end
  object bbSignIn: TBitBtn
    Left = 240
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Logowanie'
    TabOrder = 0
    OnClick = bbSignInClick
  end
end
