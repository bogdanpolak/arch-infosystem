// ---------------------------------------------------------------------------
#include <memory>
#include <System.JSON.hpp>
#include <System.IOUtils.hpp>
// ---------------------------------------------------------------------------
#include "web_employee.h"
#include "helper_json.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TComponentClass WebModuleClass = __classid(TWebModule1);
// ---------------------------------------------------------------------------

__fastcall TWebModule1::TWebModule1(TComponent* Owner) : TWebModule(Owner) {
}
// ---------------------------------------------------------------------------

void addResonseHeader_AllowCORS(TWebResponse *Response) {
	// Cross-Origin Resource Sharing (CORS)
	// https://developer.mozilla.org/en-US/docs/Web/HTTP/CORS
	// ---------
	Response->SetCustomHeader("Access-Control-Allow-Origin", "*");
	Response->SetCustomHeader("Access-Control-Allow-Headers",
		"X-Requested-With");
}
// ---------------------------------------------------------------------------

bool CheckRestRequest(TWebRequest* Request, TMethodType Method,
	const String Path) {
	bool isRequestMatch = (Request->MethodType == Method) &&
		(Request->PathInfo == Path);
	return isRequestMatch;
}

// ---------------------------------------------------------------------------
TJSONValue* GetRequestBodyAsJson(TWebRequest* Request) {
	return NULL;
}

/*
 uses
 System.JSON, Web.HTTPApp, System.SysUtils;

 const
 JSONContentType = 'application/json';

 function TryGetRequestBodyAsJson(Request: TWebRequest;
 var jv: TJSONValue): boolean;
 begin
 try
 if Request.ContentType <> JSONContentType then
 raise Exception.Create('Unsupported HTTP request content-type. ' +
 'Received: ' + Request.ContentType + '. Expected: '+JSONContentType);
 jv := TJSONObject.ParseJSONValue(Request.Content);
 Result := True;
 except
 on E: Exception do
 Result := False;
 end;
 end;
 */
// ---------------------------------------------------------------------------

void GenerateOkejResponse(TWebResponse *Response, String const Message) {
	Response->ContentType = "application/json";
	Response->ContentEncoding = "utf-8";
	Response->Content = "{\"status\":\"OK\", \"Message\":" + Message + "}";
}
// ---------------------------------------------------------------------------

void GenerateErrorResponse(TWebResponse *Response, int HttpStatusCode,
	String const Message) {
	// HTTP Status Codes with explanation:
	// http://www.restapitutorial.com/httpstatuscodes.html
	Response->StatusCode = HttpStatusCode;
	Response->ContentType = "application/json";
	Response->ContentEncoding = "utf-8";
	Response->Content = "{\"status\":\"error\", \"Message\":" + Message + "}";
}
// ---------------------------------------------------------------------------

void TWebModule1::ApiGetNotImplemented(TWebResponse *Response) {
	// 501 = Not Implemented
	// http://www.restapitutorial.com/httpstatuscodes.html
	GenerateErrorResponse(Response, 501, "\"Not implemented yet\"");
}
// ---------------------------------------------------------------------------

void TWebModule1::ApiGetVersion(TWebResponse *Response) {
	std::unique_ptr<TJSONObject>jResponse(new TJSONObject);
	jResponse->AddPair("server", "Employee - WebBroker 10.2 REST Server");
	jResponse->AddPair("version", "1.0");
	Response->ContentType = "application/json";
	Response->ContentEncoding = "utf-8";
	Response->Content = jResponse->ToString();
}
// ---------------------------------------------------------------------------

void TWebModule1::ApiGetEmployee(TWebResponse *Response) {
	dsEmployee->Open();
	TJSONObject* jResponse = new TJSONObject();
	jResponse->AddPair("status", "OK");
	TJSONArray* jDataTable = HelperJSON::DataSetToJson(dsEmployee);
	jResponse->AddPair("data", jDataTable);
	Response->ContentType = "application/json";
	Response->ContentEncoding = "utf-8";
	Response->Content = jResponse->ToString();

	// TODO: Dlaczego nie dzia³a? : jResponse->Free();
	// Jeœli zwalniam pamiêæ jResponse to aplikacja rzuca wyj¹tkiem o
	// niepoprawnym wskaŸniku
	// Podobny wyj¹tek dostajê jeœli u¿yjê unique_ptr na pocz¹tku metody:
	// std::unique_ptr<TJSONObject> jResponse(new TJSONObject);
}
// ---------------------------------------------------------------------------

void TWebModule1::ApiPostEmployee(TWebRequest *Request, TWebResponse *Response)
{
	TJSONValue* jValue = GetRequestBodyAsJson(Request);
	if (jValue) {
		TJSONObject* jObject = dynamic_cast<TJSONObject*>(jValue);
		if (jObject) {
			dsEmployee->Open();
			HelperJSON::InsertJsonObjectToDataSet(jObject, dsEmployee);
			String first = jObject->GetValue("FIRST_NAME")->Value();
			String last = jObject->GetValue("LAST_NAME")->Value();
			String msg =
				String().sprintf
				(L"Added new employee FIRST_NAME=%s LAST_NAME=%s", first, last);
			GenerateOkejResponse(Response, msg);
		}
	}
	else {
		// 400 Bad Request
		GenerateErrorResponse(Response, 400,
			"\"Incompatibile JSON in request body.\"");
	}
}
// ---------------------------------------------------------------------------

void __fastcall TWebModule1::WebModule1DefaultHandlerAction(TObject *Sender,
	TWebRequest *Request, TWebResponse *Response, bool &Handled) {

	if (CheckRestRequest(Request, mtGet, "/version/")) {
		ApiGetVersion(Response);
	}
	else if (CheckRestRequest(Request, mtGet, "/employee/")) {
		ApiGetEmployee(Response);
	}
	else if (CheckRestRequest(Request, mtPost, "/employee/")) {
		ApiPostEmployee(Request, Response);
	}
	else if (CheckRestRequest(Request, mtGet, "/html/")) {
		String page = TFile::ReadAllText ("..\\..\\page.html");
		page = StringReplace (page,"{%name%}","Bogdan Polak",TReplaceFlags());
		Response->Content = page;
	}
	else {
		ApiGetNotImplemented(Response);
	}
	Handled = true;
}
// ---------------------------------------------------------------------------
