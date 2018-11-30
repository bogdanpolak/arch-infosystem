//---------------------------------------------------------------------------

#ifndef helper_jsonH
#define helper_jsonH
//---------------------------------------------------------------------------
#include <System.SysUtils.hpp>
#include <Data.DB.hpp>
#include <System.JSON.hpp>
//---------------------------------------------------------------------------

namespace HelperJSON {
	TJSONArray* DataSetToJson(TDataSet* ds);
	void InsertJsonObjectToDataSet (TJSONObject* jObject, TDataSet* DataSet);
}

//---------------------------------------------------------------------------
#endif
