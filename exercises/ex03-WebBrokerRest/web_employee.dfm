object WebModule1: TWebModule1
  OldCreateOrder = False
  Actions = <
    item
      Default = True
      Name = 'DefaultHandler'
      PathInfo = '/'
      OnAction = WebModule1DefaultHandlerAction
    end>
  Height = 230
  Width = 415
  object FDConnection1: TFDConnection
    Params.Strings = (
      'ConnectionDef=FB_Employee')
    LoginPrompt = False
    Left = 32
    Top = 16
  end
  object dsEmployee: TFDQuery
    Connection = FDConnection1
    UpdateOptions.AssignedValues = [uvCheckReadOnly]
    UpdateOptions.CheckReadOnly = False
    SQL.Strings = (
      'SELECT * FROM EMPLOYEE')
    Left = 104
    Top = 16
    object dsEmployeeEMP_NO: TSmallintField
      AutoGenerateValue = arAutoInc
      FieldName = 'EMP_NO'
      Origin = 'EMP_NO'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
    end
    object dsEmployeeFIRST_NAME: TStringField
      FieldName = 'FIRST_NAME'
      Origin = 'FIRST_NAME'
      Required = True
      Size = 15
    end
    object dsEmployeeLAST_NAME: TStringField
      FieldName = 'LAST_NAME'
      Origin = 'LAST_NAME'
      Required = True
    end
    object dsEmployeePHONE_EXT: TStringField
      FieldName = 'PHONE_EXT'
      Origin = 'PHONE_EXT'
      Size = 4
    end
    object dsEmployeeHIRE_DATE: TSQLTimeStampField
      AutoGenerateValue = arDefault
      FieldName = 'HIRE_DATE'
      Origin = 'HIRE_DATE'
    end
    object dsEmployeeDEPT_NO: TStringField
      FieldName = 'DEPT_NO'
      Origin = 'DEPT_NO'
      Required = True
      FixedChar = True
      Size = 3
    end
    object dsEmployeeDepartmentName: TStringField
      FieldKind = fkLookup
      FieldName = 'DepartmentName'
      LookupDataSet = dsDepartment
      LookupKeyFields = 'DEPT_NO'
      LookupResultField = 'DEPARTMENT'
      KeyFields = 'DEPT_NO'
      Size = 50
      Lookup = True
    end
    object dsEmployeeJOB_CODE: TStringField
      FieldName = 'JOB_CODE'
      Origin = 'JOB_CODE'
      Required = True
      Size = 5
    end
    object dsEmployeeJobName: TStringField
      FieldKind = fkLookup
      FieldName = 'JobName'
      LookupDataSet = dsJob
      LookupKeyFields = 'JOB_CODE'
      LookupResultField = 'JOB_TITLE'
      KeyFields = 'JOB_CODE'
      Size = 50
      Lookup = True
    end
    object dsEmployeeJOB_GRADE: TSmallintField
      FieldName = 'JOB_GRADE'
      Origin = 'JOB_GRADE'
      Required = True
    end
    object dsEmployeeJOB_COUNTRY: TStringField
      FieldName = 'JOB_COUNTRY'
      Origin = 'JOB_COUNTRY'
      Required = True
      Size = 15
    end
    object dsEmployeeSALARY: TBCDField
      FieldName = 'SALARY'
      Origin = 'SALARY'
      Required = True
      Precision = 18
      Size = 2
    end
    object dsEmployeeFULL_NAME: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'FULL_NAME'
      Origin = 'FULL_NAME'
      ProviderFlags = []
      ReadOnly = True
      Size = 37
    end
    object dsEmployeeJobPosition: TStringField
      FieldKind = fkCalculated
      FieldName = 'JobPosition'
      Size = 50
      Calculated = True
    end
  end
  object dsJob: TFDQuery
    Connection = FDConnection1
    SQL.Strings = (
      'SELECT * FROM JOB')
    Left = 104
    Top = 64
  end
  object dsDepartment: TFDQuery
    Connection = FDConnection1
    SQL.Strings = (
      'SELECT * FROM DEPARTMENT')
    Left = 104
    Top = 112
  end
end
