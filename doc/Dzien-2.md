# Agenda

1. [Czysty oraz bezpieczny kod C++](#czysty-oraz-bezpieczny-kod-c)
2. Zasady Clean Code
3. Użycie biblioteki STL
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

Przejrzyj:

* Programming in C++Builder (book)
    * http://www.informit.com/articles/article.aspx?p=130844
* Object Pascal to C++ Builder Coding
    * https://www.davidghoyle.co.uk/WordPress/?page_id=1327



# Biblioteka STL / stdlib

## Struktury STL

https://en.wikipedia.org/wiki/Standard_Template_Library

## Algorytmy STL

https://en.wikipedia.org/wiki/Algorithm_(C%2B%2B)

## Zarządzanie pamięcią (stdlib)

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
