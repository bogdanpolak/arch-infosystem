# Agenda

1. [Czysty oraz bezpieczny kod C++](#czysty-oraz-bezpieczny-kod-c)
2. [Zasady Clean Code](#zasady-clean-code)
3. [Użycie bibliotek STL, stdlib, Boost](#biblioteka-stl--stdlib)
4. Refaktoryzacja kodu i reguły DRY w tym samym projekcie

# Czysty oraz bezpieczny kod C++

* [Jason Turner - C++ Coding Standards: Style](./CodingStandardsStyle.md)
    * Opisowe i spójne nazewnictwo
    * Rozróżniaj pliki C++ od plików C
    * Użyj `nullptr`
    * Komentarze
    * Nigdy nie używaj `using` w pliku nagłówkowym
    * Wpisuj strażników w nagłówkach (`#ifnded` & `#define`)
    * Wcięcia kodu
    * Nawiasy `{}` są wymagane dla bloków
    * Pisz linie "rozsądnej" długości
    * Użyj `"..."` do włączania lokalnych plików nagłówkowych (`include')
    * Inicjuj zmienne będące członkami klasy lub struktury (atrybuty)
    * Deklaruj struktury w plikach nagłówkowych, kiedy to tylko możliwe
    * Zawsze używaj przestrzeni nazw
    * Unikaj makr kompilatora

* [Jason Turner - C++ Coding Standards: Performanceand Safety](./CodingStandardsPerformanceSafety.md)
    * Ogranicz zasięg (widoczność) zmiennych
    * Użyj wyjątków zamiast zwracania nr błędów jako wyniku
    * Unikaj dostępu bezpośrednio do pamięci
    * Unikaj danych globalnych
    * Preferuj pre-increment niż post-increment
    * Używaj jak najwięcej stałych `const`
    * Preferuj operacje na stosach do operacji sterty

* Project Chromium (Blink) - C++ Style Guide
    * https://chromium.googlesource.com/chromium/src/+/master/styleguide/c++/
    * [Chromium C++ style guide](https://chromium.googlesource.com/chromium/src/+/master/styleguide/c++/c++.md)
        * Ogólny dokument
    * [Blink C++ Style Guide](https://chromium.googlesource.com/chromium/src/+/master/styleguide/c++/blink-c++.md)
        * Style Guide dla projektu Blink (silnik przeglądarki Google)
        * [Repozytorium projektu Blink](https://chromium.googlesource.com/chromium/src/+/master/third_party/blink/)
        * Kilka ciekawych przykładów konwencji nazywania
    * [C++ Dos and Don'ts](https://sites.google.com/a/chromium.org/dev/developers/coding-style/cpp-dos-and-donts)
        * Minimalizuj kod w nagłówkach
        * Nie wpisuj kodu w nagłówkach
            * Dużo ważnych porad w tym temacie
        * Zmienne statyczne
        * Zmienna inicjalizacja
        * Preferuj `struct` bardziej niż  `pairs` / `tuples`
        * Preferuj `std::make_unique` niż `base::WrapUnique`
        * Nie używaj auto do dedukcji bezpośredniego wskaźnika
        * Używaj poprawnie `const`
        * Staraj się używać `=default` 

* Google C++ Style Guide
    * https://google.github.io/styleguide/cppguide.html

* [Programming in C++Builder](http://www.informit.com/articles/article.aspx?p=130844)
    * By Jamie Allsop, Daniel Butterfield, Jarrod Hollingworth, Bob Swart
    * Date: Dec 8, 2000 (C++Builder 5 Developer's Guide)
	* Coding Style to Improve Readability
		* Code Layout
		* Sensible Naming
		* Comments
	* Better Programming Practices in C++Builder
		* Use a String Class Instead of char*
		* Understand References and Use Them Where Appropriate
		* Avoid Using Global Variables
		* Understand and Use const in Your Code
		* Be Familiar with the Principles of Exceptions
		* Understand and Use C++-Style Casts
		* Know When to Use the Preprocessor
		* Learn About and Use the C++ Standard Library

* [Object Pascal to C++ Builder Coding](https://www.davidghoyle.co.uk/WordPress/?page_id=1327)
    * Proste przykłady jak kod Delphi mapuje się na kod C++

Lektura:
* [C++17 STL. Receptury](https://helion.pl/ksiazki/c-17-stl-receptury-jacek-galowicz,cpp17r.htm)
    * Helion, 456  stron, Tłumaczenie: Robert Górczyński
    * Autor: Jacek Galowicz
    * Tytuł oryginału: C++17 STL Cookbook
    * O autorze: Jacek Galowicz do niedawna implementował sterowniki jądra w C i C++. Tworzył też grafiki 3D i bazy danych, zajmował się również komunikacją sieciową. Ostatnio pracuje w firmach Intel oraz FireEye, gdzie programuje systemy operacyjne o dużej wydajności i wysokim poziomie bezpieczeństwa, wykorzystując wirtualizację Intel x86. Jego ogromną pasją są nowoczesne implementacje C++ na niskim poziomie i łączenie w kodzie wysokiej wydajności z eleganckim stylem.
    * Przykładowa recenzja: Pretty much the only real resource for large quantities of example code using C++17 and experimental C++ features. I primarily used the filesystem stuff, and the experimental filesystem is absolutely awesome for how much easier it makes iterating through directories, checking a file's existence, and querying information about files (regardless of platform!). Otherwise, it covers useful but obscure utility classes pretty well, and espouses the use of important things like the lock classes that wrap mutexes in a safer manner.



# Zasady Clean Code

 Klucz | Treść |
| - | - |
| Tytuł | Czysty kod. Podręcznik dobrego programisty |
| Autor | [Robert C. Martin](https://en.wikipedia.org/wiki/Robert_C._Martin) |
| Wydawnictwo | Helion, [link do książki na stronie helion.pl](https://helion.pl/ksiazki/czysty-kod-podrecznik-dobrego-programisty-robert-c-martin,czykov.htm#section7_shift) |
| Tytuł oryginału | Clean Code: A Handbook of Agile Software Craftsmanship |

Poniżej podane są tylko wybrane sekcje z każdego rozdziału

* Rozdział 2. Znaczące nazwy
    * Używaj nazw przedstawiających intencje
    * Tworzenie nazw, które można wymówić
    * Unikanie odwzorowania mentalnego (nie nazywaj zmiennej tekstowej i)
    * Nazwy klas (TFoo)
    * Nazwy metod (Z dużej litery)
* Rozdział 3. Funkcje
    * Małe funkcje!
    * Wykonuj jedną czynność
    * Czytanie kodu od góry do dołu zasada zstępująca
    * Instrukcje switch
    * Korzystanie z nazw opisowych
    * Argumenty funkcji
    * Listy argumentów
    * Wyodrębnienie bloków try-catch
* Rozdział 4. Komentarze
    * Czytelny kod nie wymaga komentarzy
    * Wyjaśnianie zamierzeń
    * Ostrzeżenia o konsekwencjach
    * Komentarze TODO
    * Wzmocnienie
    * Komentarze Javadoc w publicznym API
    * Nie używaj komentarzy, jeżeli można użyć funkcji lub zmiennej
    * Zakomentowany kod
* Rozdział 5. Formatowanie
    * Zasady zespołowe
    * Zasady formatowania wujka Boba
* Rozdział 6. Obiekty i struktury danych
    * Abstrakcja danych
    * Antysymetria danych i obiektów
    * Prawo Demeter
    * Obiekty transferu danych (Active Record)
* Rozdział 7. Obsługa błędów
    * Użycie wyjątków zamiast kodów powrotu
    * Rozpoczynanie od pisania instrukcji try-catch-finally
    * Nie zwracamy null
* Rozdział 9. Testy jednostkowe
    * Trzy prawa TDD
    * ...
* Rozdział 10. Klasy
    * Organizacja klas
        * Hermetyzacja
    * Klasy powinny być małe!
        * Zasada pojedynczej odpowiedzialności
        * Spójność
        * Utrzymywanie spójności powoduje powstanie wielu małych klas
    * Organizowanie zmian
        * Izolowanie modułów kodu przed zmianami
* Rozdział 11. Systemy
    * Jak budowałbyś miasto?
    * Oddzielenie konstruowania systemu od jego używania
        * Wydzielenie modułu main
        * Fabryki
        * Wstrzykiwanie zależności
    * Testowanie architektury systemu
* Rozdział 17. Zapachy kodu i heurystyki


# Biblioteka STL / stdlib

> Dużo większe możliwości i większą czytelność kodu zapewniają wersje zgodne z C++11, C++14 oraz C++17

* Struktury STL
    * https://en.wikipedia.org/wiki/Standard_Template_Library
    * `vector`
    * `map`
    * `set`
    * `pair`
    * iteratory
* Algorytmy STL
    * https://en.wikipedia.org/wiki/Algorithm_(C%2B%2B)
    * sortowanie
    * redukcja
    * podział
    * wyłączanie
    * kopiowanie (kopiowanie warunkowe)
* Zarządzanie pamięcią (stdlib)

> Zobacz ćwiczenie: ex02_STL_Demo

Wersja klasyczna:

```cpp
TCustomer* cust = new TCustomer();
try
{
    ...
}
__finally
{
    delete cust;
}
```

wersja STD:

```cpp
#include <memory>
std::unique_ptr<TCustomer> cust(new TCustomer);
...
```

Wsparcie C++Builder-a dla biblioteki STD:

* [David Millington - Blog Post](https://community.idera.com/developer-tools/b/blog/posts/new-in-rad-studio-10-3-c-17-asynchronous-c-code-completion-and-more)
* [RAD Studio 10.3 Rio - What's New](http://docwiki.embarcadero.com/RADStudio/Rio/en/What%27s_New#C.2B.2B)


### Biblioteka Boost
* Instalacja przez GetIt Package Manager (po zainstalowaniu IDE)
* Ogromne możliwości zarówno przez bardzo użyteczne szablony, jak również zaawansowane struktury oraz wydajne algorytmy
* Bibliotek Boost może zastępować w wielu miejscach możliwości oferowane przez kompilatory C++17
* Przykładowe struktury danych:
    * Drzewo i wyszukiwanie po drzewie
    * Graf i algorytmy grafowe (przejście w szerz, przejście w głąb)
    * Maszyna stanowa
