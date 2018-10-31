object SeekClientDlg: TSeekClientDlg
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Wyszukiwanie klient'#243'w'
  ClientHeight = 63
  ClientWidth = 394
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 293
    Height = 45
    Caption = ' Identyfikator klienta lub jego nazwa '
    TabOrder = 0
    object Edit1: TEdit
      Left = 8
      Top = 16
      Width = 277
      Height = 21
      TabOrder = 0
      OnKeyPress = Edit1KeyPress
    end
  end
  object Button1: TButton
    Left = 308
    Top = 20
    Width = 77
    Height = 25
    Caption = 'Znajd'#378
    TabOrder = 1
    OnClick = Button1Click
  end
end
