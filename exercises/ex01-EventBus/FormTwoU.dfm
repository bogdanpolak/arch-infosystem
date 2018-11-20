object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 243
  ClientWidth = 473
  Color = clBtnFace
  DoubleBuffered = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 72
    Width = 31
    Height = 13
    Caption = 'Label1'
  end
  object tmrAnimate: TTimer
    Interval = 50
    OnTimer = tmrAnimateTimer
    Left = 24
    Top = 8
  end
end
