// ---------------------------------------------------------------------------

#pragma hdrstop

// ---------------------------------------------------------------------------
#include "helper_json.h"
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <System.DateUtils.hpp>
#include <Data.SqlTimSt.hpp>
#include <Data.FmtBcd.hpp>
#include <Data.DBXJSONCommon.hpp>
// ---------------------------------------------------------------------------
#pragma package(smart_init)

TJSONValue* BooleanToJSON(bool const value) {
	if (value)
		return new TJSONTrue();
	else
		return new TJSONFalse();
}

String DateToISODate(TDateTime const dt) {
	return FormatDateTime("yyyy-mm-dd", dt);
}

TJSONObject* DataRowToJSON(TDataSet* ds) {
	TJSONObject* jDataRow = new TJSONObject();
	for (int i = 0; i < ds->FieldCount; ++i) {
		TField* fld = ds->Fields->Fields[i];
		TJSONValue* jv;
		if (!fld->IsNull) {
			switch (fld->DataType) {
			case (TFieldType::ftBoolean):
				jv = BooleanToJSON(fld->AsBoolean);
				break;
			case (TFieldType::ftInteger):
			case (TFieldType::ftSmallint):
			case (TFieldType::ftShortint):
				jv = new TJSONNumber(fld->AsInteger);
				break;
			case (TFieldType::ftLargeint):
				jv = new TJSONNumber(fld->AsLargeInt);
				break;
			case (TFieldType::ftSingle):
			case (TFieldType::ftFloat):
				jv = new TJSONNumber(fld->AsFloat);
				break;
			case (ftString):
			case (ftWideString):
			case (ftMemo):
			case (ftWideMemo):
				jv = new TJSONString(fld->AsString);
				break;
			case (TFieldType::ftDate):
				jv = new TJSONString(DateToISODate(fld->AsDateTime));
				break;
				/*
				 TFieldType.ftTimeStamp,
				 TFieldType.ftDateTime:
				 jv = TJSONString.Create(System.DateUtils.DateToISO8601(fld.AsDateTime, False));
				 break;
				 TFieldType.ftCurrency:
				 jv = TJSONNumber.Create(fld.AsCurrency);
				 break;
				 TFieldType.ftBCD,
				 TFieldType.ftFMTBcd:
				 jv = TJSONNumber.Create(Data.FmtBcd.BcdToDouble(fld.AsBcd));
				 break;
				 TFieldType.ftGraphic, TFieldType.ftBlob, TFieldType.ftStream:
				 jv = BlobFieldToJSONArray(fld as TBlobField);
				 break;
				 // TODO: complete support for some fields types in datarow to JSON
				 // TFieldType.ftTime:   // unsupported field
				 // TFieldType.ftDataSet:  // unsuppored nested datasets
				 else
				 raise EDataRowToJSONConvertError.CreateFmt
				 ('Unsupported field type for: "%s"', [fldName]);
				 end;
				 Result.AddPair(fldName, jv);
				 */
			default: ;
			}
		}
		else {
			jv = new TJSONNull();
		}
		if (jv) {
			jDataRow->AddPair(fld->FieldName, jv);
		}
	}
	return jDataRow;
}
// ---------------------------------------------------------------------------

TJSONArray* HelperJSON::DataSetToJson(TDataSet* ds) {
	if (ds && ds->Active && !ds->IsEmpty()) {
		TBookmark bmk = ds->GetBookmark();
		TJSONArray* jDataTable = new TJSONArray();
		ds->First();
		while (!ds->Eof) {
			jDataTable->AddElement(DataRowToJSON(ds));
			ds->Next();
		}
		if (ds->BookmarkValid(bmk)) {
			ds->GotoBookmark(bmk);
			ds->FreeBookmark(bmk);
		}
		return jDataTable;
	}
	else {
		return NULL;
	}
}
// ---------------------------------------------------------------------------
// Insert JSON data to dataset
// ---------------------------------------------------------------------------

void HelperJSON::InsertJsonObjectToDataSet(TJSONObject* jObject,
	TDataSet* DataSet) {
    // TODO: Przet³umaczyæ z Delphi
}
// ---------------------------------------------------------------------------

/*

 procedure FillDataSetFieldsWithJson(jObject: TJSONObject; DataSet: TDataSet);
 var
 i: Integer;
 fld: TField;
 jPair: TJSONPair;
 jv2: TJSONValue;
 begin
 for i := 0 to DataSet.FieldCount - 1 do
 begin
 fld := DataSet.Fields[i];
 jPair := jObject.Get(fld.FieldName);
 if Assigned(jPair) then
 begin
 jv2 := jPair.JsonValue;
 if jv2 is TJSONNull then
 fld.Clear
 else if fld.DataType = TFieldType.ftTimeStamp then
 fld.AsDateTime := System.DateUtils.ISO8601ToDate(jv2.Value)
 else
 fld.AsString := jv2.Value;
 end;
 end;
 end;

 InsertJsonObjectToDataSet (jObject: TJSONObject; DataSet: TDataSet);
 ds.Insert;
 FillDataSetFieldsWithJson (jObject: TJSONObject; DataSet: TDataSet);
 ds.Post;

 procedure TWebModule1.ApiPostEmployee(Request: TWebRequest;
 Response: TWebResponse);
 var
 jValue: TJSONValue;
 jObject: TJSONObject;
 jResponse: TJSONObject;
 begin
 if Utils.RESTAPI.WebBroker.TryGetRequestBodyAsJson(Request, jValue) then
 begin
 if jValue is TJSONObject then
 begin
 jObject := jValue as TJSONObject;
 dsEmployee.Open();
 dsEmployee.Insert;
 Utils.JSON.ToDataSet.JsonToDataSetFields(jObject, dsEmployee);
 dsEmployee.Post;
 dsEmployee.Close;
 jResponse := TJSONObject.Create;
 jResponse.AddPair('status', 'OK').AddPair('message',
 'Added employee FIRST_NAME=' + jObject.GetValue('FIRST_NAME').Value +
 ' LAST_NAME=' + jObject.GetValue('LAST_NAME').Value);
 Response.ContentType := 'application/json';
 Response.ContentEncoding := 'utf-8';
 Response.Content := jResponse.ToString;
 jResponse.Free;
 end;
 end
 else
 begin
 Response.StatusCode := 400; // 400 Bad Request
 Response.Content :=
 '{"status":"Error", "Message":"Incompatibile request format."}';
 end;
 end;

 */

/*

 uses
 System.SysUtils, Data.DB, System.JSON;

 type
 EDataRowToJSONConvertError = class(Exception);

 function DataRowToJSON(ds: TDataSet): TJSONObject;
 function DataSetToJson(ds: TDataSet): TJSONArray;


 implementation

 uses
 System.Classes, System.DateUtils, Data.SqlTimSt, Data.FmtBcd,
 Data.DBXJSONCommon;

 type
 TDataSetToJsonHelper = class helper for TDataSet
 function AsJSON(): TJSONArray;
 end;

 function BooleanToJSON(const b: Boolean): TJSONValue;
 begin
 if b then
 Result := TJSONTrue.Create
 else
 Result := TJSONFalse.Create;
 end;

 function BlobFieldToJSONArray(fld: TBlobField): TJSONArray;
 var
 ms: TMemoryStream;
 begin
 if fld.IsNull then
 raise EDataRowToJSONConvertError.Create
 ('Cant conver NULL stream into JSON.')
 else
 begin
 ms := TMemoryStream.Create;
 try
 TBlobField(fld).SaveToStream(ms);
 ms.Position := 0;
 Result := Data.DBXJSONCommon.TDBXJSONTools.StreamToJSON(ms, 0, ms.Size);
 finally
 FreeAndNil(ms);
 end;
 end;
 end;

 function DateToISODate(dt: TDateTime): string;
 begin
 Result := System.SysUtils.FormatDateTime('yyyy-mm-dd', dt);
 end;

 function DataRowToJSON(ds: TDataSet): TJSONObject;
 var
 i: Integer;
 fldName: string;
 fld: TField;
 jv: TJSONValue;
 begin
 Result := TJSONObject.Create;
 for i := 0 to ds.FieldCount - 1 do
 begin
 fld := ds.Fields[i];
 fldName := ds.Fields[i].FieldName;
 if ds.Fields[i].IsNull then
 Result.AddPair(fldName, TJSONNull.Create)
 else
 begin
 case ds.Fields[i].DataType of
 TFieldType.ftBoolean:
 jv := BooleanToJSON(fld.AsBoolean);
 TFieldType.ftInteger, TFieldType.ftSmallint, TFieldType.ftShortint:
 jv := TJSONNumber.Create(fld.AsInteger);
 TFieldType.ftLargeint:
 jv := TJSONNumber.Create(fld.AsLargeInt);
 TFieldType.ftSingle, TFieldType.ftFloat:
 jv := TJSONNumber.Create(fld.AsFloat);
 ftString, ftWideString, ftMemo, ftWideMemo:
 jv := TJSONString.Create(fld.AsString);
 TFieldType.ftDate:
 jv := TJSONString.Create(DateToISODate(fld.AsDateTime));
 TFieldType.ftTimeStamp,
 TFieldType.ftDateTime:
 jv := TJSONString.Create(System.DateUtils.DateToISO8601(fld.AsDateTime, False));
 TFieldType.ftCurrency:
 jv := TJSONNumber.Create(fld.AsCurrency);
 TFieldType.ftBCD,
 TFieldType.ftFMTBcd:
 jv := TJSONNumber.Create(Data.FmtBcd.BcdToDouble(fld.AsBcd));
 TFieldType.ftGraphic, TFieldType.ftBlob, TFieldType.ftStream:
 jv := BlobFieldToJSONArray(fld as TBlobField);
 // TODO: complete support for some fields types in datarow to JSON
 // TFieldType.ftTime:   // unsupported field
 // TFieldType.ftDataSet:  // unsuppored nested datasets
 else
 raise EDataRowToJSONConvertError.CreateFmt
 ('Unsupported field type for: "%s"', [fldName]);
 end;
 Result.AddPair(fldName, jv);
 end;
 end;
 end;

 function DataSetToJson(ds: TDataSet): TJSONArray;
 var
 bmk: TBookmark;
 begin
 if not(ds.Active) or (ds = nil) or ds.IsEmpty then
 Result := nil
 else begin
 bmk := ds.GetBookmark;
 Result := TJSONArray.Create;
 try
 ds.First;
 while not ds.Eof do
 begin
 Result.AddElement( DataRowToJSON(ds) );
 ds.Next;
 end;
 if ds.BookmarkValid(bmk) then
 ds.GotoBookmark(bmk);
 finally
 if ds.BookmarkValid(bmk) then
 ds.FreeBookmark(bmk);
 end;
 end;
 end;

 function TDataSetToJsonHelper.AsJSON: TJSONArray;
 var
 bmk: TBookmark;
 begin
 if not(self.Active) or (self = nil) or self.IsEmpty then
 Result := nil
 else begin
 bmk := self.GetBookmark;
 Result := TJSONArray.Create;
 try
 self.First;
 while not self.Eof do
 begin
 Result.AddElement( DataRowToJSON(self) );
 self.Next;
 end;
 if self.BookmarkValid(bmk) then
 self.GotoBookmark(bmk);
 finally
 Result.Free;
 if self.BookmarkValid(bmk) then
 self.FreeBookmark(bmk);
 end;
 end;
 end;

 */
