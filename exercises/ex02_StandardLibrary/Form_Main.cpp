// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Form_Main.h"
// ---------------------------------------------------------------------------
#include <algorithm>
#include <functional>
// using namespace std;
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// ---------------------------------------------------------------------------
#define ARRAY_SIZE(ar) (sizeof(ar) / sizeof(ar[0]))
#define ARRAY_END(ar) (ar + ARRAY_SIZE(ar))

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void TForm1::ReportCompilerPlatform() {
#if !defined(__clang__) && defined(_WIN32) && !defined(_WIN64)
	Memo1->Lines->Add("Classic Win32 C++ compiler");
#endif
#if defined(__clang__) && defined(_WIN32) && !defined(_WIN64)
	Memo1->Lines->Add("Win32 C++ Clang compiler");
#endif
#ifdef _WIN64
	Memo1->Lines->Add("Win64 C++ Clang compiler");
#endif
	// #ifdef __BORLANDC__

}

// ---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender) {
	Memo1->Align = alClient;
	Memo1->Clear();
	ReportCompilerPlatform();
	randomize();
}

// ---------------------------------------------------------------------------
void TForm1::Log(String LogMessage) {
	Memo1->Lines->Add(LogMessage);
}

// ---------------------------------------------------------------------------
void TForm1::LogSparator() {
	Memo1->Lines->Add("------------------------------------------");
}

// ---------------------------------------------------------------------------
void TForm1::LogMessageAndInt(String Message, int value) {
	Memo1->Lines->Add(Message + ": " + value);
}

// ---------------------------------------------------------------------------
void TForm1::LogVectorElems(int ident, const std::vector<int>vector) {
	String elems = "";
	for (unsigned int i = 0; i < vector.size(); i++) {
		elems += (i == 0 ? IntToStr(vector[i]) : ", " + IntToStr(vector[i]));
	}
	String echo = String().StringOfChar(' ', ident) + "[" + elems + "]";
	Memo1->Lines->Add(echo);
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::btnCapasityClick(TObject *Sender) {
	LogSparator();
	std::vector<int>vecInt;
	Log(L"Initalizing vector capacity to 100");
	vecInt.reserve(100);
	Log(String().sprintf(L"Size : %d", vecInt.size()));
	Log(String().sprintf(L"Capacity : %d", vecInt.capacity()));
	Log((vecInt.empty() ? L"Vector is empty" : L"Vector is not empty"));
	const int size = 25;
	Log(String().sprintf(L"Adding %d elements to the vector", size));
	vecInt.resize(size);
	Log(String().sprintf(L"Size : %d", vecInt.size()));
	Log(String().sprintf(L"Capacity : %d", vecInt.capacity()));
	Log(String().sprintf(L"Max_Size : %d", vecInt.max_size()));
	Log((vecInt.empty() ? L"Vector is empty" : L"Vector is not empty"));
#ifdef __clang__
	vecInt.shrink_to_fit();
	Log(String().sprintf(L"Size (after shrink_to_fit) : %d", vecInt.size()));
	Log(String().sprintf(L"Capacity (after shrink_to_fit) : %d",
		vecInt.capacity()));
#else
	Log(L"\"std::vector::shrink_to_fit\" is not supported");
#endif
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::btnIteratorsClick(TObject *Sender) {
	LogSparator();
	String elems1 = "    ";
	String elems2 = "    ";
#ifdef __clang__
	std::vector<int>vecInt {
		1, 2, 5, 7, 11, 13, 17, 19
	};
	for (auto it1 = vecInt.begin(); it1 != vecInt.end(); it1++) {
		elems1 += IntToStr(*it1) + " ";
	}
	for (auto it2 = vecInt.rbegin(); it2 != vecInt.rend(); it2++)
		elems2 += IntToStr(*it2) + " ";
#else
	static const int arr[] = {1, 2, 5, 7, 11, 13, 17, 19};
	int arrSize = ARRAY_SIZE(arr);
	std::vector<int>vecInt(arr, arr + arrSize); // ARRAY_END(arr));
	std::vector<int>::iterator it1;
	for (it1 = vecInt.begin(); it1 != vecInt.end(); it1++)
		elems1 += IntToStr(*it1) + " ";
	std::reverse_iterator<std::vector<int>::iterator>it2;
	for (it2 = vecInt.rbegin(); it2 != vecInt.rend(); it2++)
		elems2 += IntToStr(*it2) + " ";
#endif
	Log(L"List using iterator:");
	Log(elems1);
	Log(L"List using reverse iterator:");
	Log(elems2);
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::btnElementAccessClick(TObject *Sender) {
	static const int prime[] = {1, 2, 5, 7, 11, 13, 17, 19};
	std::vector<int>vecInt(prime, ARRAY_END(prime));
	int initCount = vecInt.size();
	Log(L"Prime numbers. First " + IntToStr(initCount));
	LogVectorElems(4, vecInt);
	int value = vecInt.at(4);
	LogMessageAndInt("Fifth prime number is: ", value);
	value = vecInt[5];
	LogMessageAndInt("Sixth prime number is: ", value);
	Log(L"Adding 9th prime number");
	vecInt.push_back(23);
	LogVectorElems(4, vecInt);
	Log(L"Removing last item");
	vecInt.pop_back();
	LogVectorElems(4, vecInt);
	Log(L"Adding two non prime numbers (3 and 4)");
	vecInt.insert(vecInt.begin() + 2, 3);
	vecInt.insert(vecInt.begin() + 3, 4);
	LogVectorElems(4, vecInt);
	Log(L"Remove two non prime numbers");
	vecInt.erase(vecInt.begin() + 2);
	vecInt.erase(vecInt.begin() + 2);
	LogVectorElems(4, vecInt);
	// ---------------------------------------------------
	// **** Ró¿nica miedzy emplace a insert ****
	// **** emplace - C++11
	// struct Foo { Foo(int n, double x); };
	// std::vector<Foo> v;
	// v.emplace(someIterator, 42, 3.1416);
	// v.insert(someIterator, Foo(42, 3.1416));
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::btnSortIntegersClick(TObject *Sender) {
	LogSparator();
	std::vector<int>vecInt;
	Log(L"* Fill vector with random data:");
	for (int i = 1; i <= 10; i++)
		vecInt.push_back(random(100));
	LogVectorElems(4, vecInt);
	Log(L"* Sorts vector:");
	// required: #include <algorithm>
	std::sort(vecInt.begin(), vecInt.end());
	LogVectorElems(4, vecInt);
	Log(L"* Sorts vector (descending order):");
#ifdef __clang__
	// C++11:
	// Mo¿na sortowaæ dowolne struktury i klasy
	std::sort(vecInt.begin(), vecInt.end(), [](int& cmp1, int& cmp2)->bool
	{return cmp1 > cmp2;});
#else
	// Classic STL - pre C++11
	// required: #include <functional>
	std::sort(vecInt.begin(), vecInt.end(), std::greater<int>());
#endif
	LogVectorElems(4, vecInt);
}

// ---------------------------------------------------------------------------
struct Person {
	String fullname;
	TDateTime birthday;

	Person(String fullname, TDateTime birthday) {
		this->fullname = fullname;
		this->birthday = birthday;
	}

	operator String() {
		return fullname + ", " + FormatDateTime("dd mmmm", birthday) + " (" +
			FormatDateTime("yyyy", birthday) + ")";
	}

	bool operator < (const Person& rsh) {
		Word yyL, mmL, ddL;
		Word yyR, mmR, ddR;
		DecodeDate(this->birthday, yyL, mmL, ddL);
		DecodeDate(rsh.birthday, yyR, mmR, ddR);
		return (mmL < mmR) || (mmL == mmR) && (ddL < ddR);
	}
};

// ---------------------------------------------------------------------------
void __fastcall TForm1::btnStructDemoClick(TObject *Sender) {
	TFormatSettings fs = TFormatSettings::Create();
	fs.DateSeparator = '-';
	fs.ShortDateFormat = "yyyy-MM-dd";
	std::vector<Person>birthdays;
	birthdays.push_back(Person("Bogdan Polak", StrToDate("1971-04-20", fs)));
	birthdays.push_back(Person("Jan Kowalski", StrToDate("1978-02-12", fs)));
	birthdays.push_back(Person("Tomasz Tulski", StrToDate("1968-12-15", fs)));
	birthdays.push_back(Person("Pawe³ Monacki", StrToDate("1989-11-02", fs)));
	birthdays.push_back(Person("Dariusz Darski", StrToDate("1986-05-15", fs)));
	birthdays.push_back(Person("Rafa³ Rogalski", StrToDate("1995-05-01", fs)));
	for (unsigned int i = 0; i < birthdays.size(); i++)
		Log("  - " + birthdays[i]);
	std::sort(birthdays.begin(), birthdays.end());
	Log("Sortowanie wg daty urdzin (dzieñ i miesi¹c)");
	for (unsigned int i = 0; i < birthdays.size(); i++)
		Log("  - " + birthdays[i]);
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::btnClearLogClick(TObject *Sender) {
	Memo1->Clear();
}
// ---------------------------------------------------------------------------
