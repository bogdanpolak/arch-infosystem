# Agenda

1. Czysty kod C++ oraz kod bezpieczny.
2. Zasady Clean Code
3. Użycie biblioteki STL
4. Refaktoryzacja kodu i reguły DRY w tym samym projekcie

# Plan Pracy

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
