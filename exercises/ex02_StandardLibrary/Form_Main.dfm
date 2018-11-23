object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 470
  ClientWidth = 636
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 213
    Top = 0
    Width = 5
    Height = 470
    ExplicitLeft = 188
    ExplicitHeight = 243
  end
  object GroupBox1: TGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 3
    Width = 210
    Height = 464
    Margins.Right = 0
    Align = alLeft
    Caption = 'GroupBox1'
    TabOrder = 0
    object Label1: TLabel
      AlignWithMargins = True
      Left = 5
      Top = 75
      Width = 200
      Height = 26
      Margins.Top = 0
      Margins.Bottom = 8
      Align = alTop
      Caption = 
        'Polecenia: reserve, resize, clear, size, capacity, max_size, emp' +
        'ty, shrink_to_fit'
      WordWrap = True
      ExplicitWidth = 195
    end
    object Label2: TLabel
      AlignWithMargins = True
      Left = 5
      Top = 205
      Width = 200
      Height = 26
      Margins.Top = 0
      Margins.Bottom = 8
      Align = alTop
      Caption = 
        'Inicjalizacja std::vector danymi.   Iteratory: begin, end, rbegi' +
        'n, rend'
      WordWrap = True
      ExplicitWidth = 168
    end
    object Label4: TLabel
      AlignWithMargins = True
      Left = 5
      Top = 20
      Width = 200
      Height = 19
      Margins.Top = 5
      Margins.Bottom = 5
      Align = alTop
      Alignment = taCenter
      Caption = 'std::vector'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      ExplicitWidth = 76
    end
    object Bevel1: TBevel
      AlignWithMargins = True
      Left = 5
      Top = 337
      Width = 200
      Height = 3
      Margins.Top = 5
      Margins.Bottom = 5
      Align = alTop
      ExplicitLeft = 4
      ExplicitTop = 275
    end
    object Label5: TLabel
      AlignWithMargins = True
      Left = 5
      Top = 140
      Width = 200
      Height = 26
      Margins.Top = 0
      Margins.Bottom = 8
      Align = alTop
      Caption = 'Polecenia: at(), [], push_back(), pop_back(), insert(), erase()'
      WordWrap = True
      ExplicitWidth = 158
    end
    object btnCapasity: TButton
      AlignWithMargins = True
      Left = 5
      Top = 47
      Width = 200
      Height = 25
      Align = alTop
      Caption = 'btnCapasity'
      TabOrder = 0
      OnClick = btnCapasityClick
    end
    object btnSortInt: TButton
      AlignWithMargins = True
      Left = 5
      Top = 242
      Width = 200
      Height = 25
      Align = alTop
      Caption = 'btnSortInt'
      TabOrder = 3
      OnClick = btnSortIntClick
    end
    object btnIterators: TButton
      AlignWithMargins = True
      Left = 5
      Top = 177
      Width = 200
      Height = 25
      Align = alTop
      Caption = 'btnIterators'
      TabOrder = 2
      OnClick = btnIteratorsClick
    end
    object btnClearLog: TButton
      AlignWithMargins = True
      Left = 5
      Top = 434
      Width = 200
      Height = 25
      Align = alBottom
      Caption = 'btnClearLog'
      TabOrder = 6
      OnClick = btnClearLogClick
    end
    object btnElementAccess: TButton
      AlignWithMargins = True
      Left = 5
      Top = 112
      Width = 200
      Height = 25
      Align = alTop
      Caption = 'btnElementAccess'
      TabOrder = 1
      OnClick = btnElementAccessClick
    end
    object btnStructDemo: TButton
      AlignWithMargins = True
      Left = 5
      Top = 304
      Width = 200
      Height = 25
      Align = alTop
      Caption = 'btnStructDemo'
      TabOrder = 5
      OnClick = btnStructDemoClick
      ExplicitTop = 294
    end
    object btnBinarySerachInt: TButton
      AlignWithMargins = True
      Left = 5
      Top = 273
      Width = 200
      Height = 25
      Align = alTop
      Caption = 'btnBinarySerachInt'
      TabOrder = 4
      OnClick = btnBinarySerachIntClick
      ExplicitLeft = 4
      ExplicitTop = 285
    end
  end
  object Memo1: TMemo
    AlignWithMargins = True
    Left = 232
    Top = 24
    Width = 185
    Height = 89
    Margins.Left = 0
    Margins.Top = 8
    Margins.Right = 5
    BevelKind = bkTile
    BorderStyle = bsNone
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Consolas'
    Font.Style = []
    Lines.Strings = (
      'Memo1')
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 1
  end
end
