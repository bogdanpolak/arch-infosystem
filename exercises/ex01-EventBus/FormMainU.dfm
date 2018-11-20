object FormMain: TFormMain
  Left = 0
  Top = 0
  ActiveControl = btnPostMessage1
  Caption = 'FormMain'
  ClientHeight = 331
  ClientWidth = 210
  Color = clWindow
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 3
    Width = 204
    Height = 325
    Align = alClient
    Caption = 'GroupBox1'
    Padding.Top = 10
    TabOrder = 0
    object Bevel1: TBevel
      AlignWithMargins = True
      Left = 5
      Top = 61
      Width = 194
      Height = 3
      Margins.Top = 5
      Margins.Bottom = 5
      Align = alTop
      ExplicitLeft = 2
      ExplicitTop = 56
      ExplicitWidth = 173
    end
    object Bevel2: TBevel
      AlignWithMargins = True
      Left = 5
      Top = 132
      Width = 194
      Height = 3
      Margins.Top = 5
      Margins.Bottom = 5
      Align = alTop
      ExplicitLeft = 3
      ExplicitTop = 161
      ExplicitWidth = 167
    end
    object Bevel3: TBevel
      AlignWithMargins = True
      Left = 5
      Top = 168
      Width = 194
      Height = 3
      Margins.Top = 5
      Margins.Bottom = 5
      Align = alTop
      ExplicitLeft = 3
      ExplicitTop = 181
      ExplicitWidth = 176
    end
    object btnPostMessage1: TButton
      AlignWithMargins = True
      Left = 5
      Top = 99
      Width = 194
      Height = 25
      Align = alTop
      Caption = 'btnPostMessage1'
      TabOrder = 2
      OnClick = btnPostMessage1Click
    end
    object btnShowSubscribers: TButton
      AlignWithMargins = True
      Left = 5
      Top = 28
      Width = 194
      Height = 25
      Align = alTop
      Caption = 'btnShowSubscribers'
      TabOrder = 0
      OnClick = btnShowSubscribersClick
    end
    object Edit1: TEdit
      AlignWithMargins = True
      Left = 5
      Top = 72
      Width = 194
      Height = 21
      Align = alTop
      TabOrder = 1
      Text = 'Wiadomo'#347#263' z okna g'#322#243'wnego'
    end
    object chkFastAnimataion: TCheckBox
      AlignWithMargins = True
      Left = 17
      Top = 143
      Width = 182
      Height = 17
      Margins.Left = 15
      Align = alTop
      Caption = 'chkFastAnimataion (Message2)'
      TabOrder = 3
      OnClick = chkFastAnimataionClick
    end
    object btnExit: TButton
      AlignWithMargins = True
      Left = 5
      Top = 295
      Width = 194
      Height = 25
      Align = alBottom
      Caption = 'Exit'
      TabOrder = 4
      OnClick = btnExitClick
    end
    object ColorBox1: TColorBox
      AlignWithMargins = True
      Left = 17
      Top = 179
      Width = 170
      Height = 22
      Margins.Left = 15
      Margins.Right = 15
      Align = alTop
      TabOrder = 5
      OnChange = ColorBox1Change
    end
  end
end
