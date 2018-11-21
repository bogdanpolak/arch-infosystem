# Notatki z Git-a

Wyłączenie pliku projektu z rejestrowania zmian:
```sh
git update-index --skip-worktree Project1.cbproj
```

| Opcje Git-a | Opis |
| --- | --- |
| update-index | Jest rozszerzeniem polecenia `git add`. Rejestruje zmiany w katalogu roboczym i zapisuje je do indeksu zmian. Polecenie pozwala także ustawić opcje tej rejestracji (zmiany skutkują na `git add`) |
| --skip-worktree | Ustawia bit `Skip-worktree`, czyli plik jest ignorowany w czasie kontrolowania zmian. Wyłączenie tego bitu przez opcję `--no-skip-worktree`  | 


# Notatki z C++

## Biblioteka standardowa STL

**1) Bezpieczne deklarowanie pamięci**

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

kontra:

```cpp
#include <memory>
std::unique_ptr<TCustomer> cust(new TCustomer);
...
```

**2) Referencja do metody w obiekcie `__closure`**

```cpp
// deklaracja typu wskazującego na metodę
typedef void (__closure *TNotifyCustomer)(int MessageID, TObject* Sender);
// użycie
TNotifyCustomer pingCustomer = NotyficationManager->CustomerNotyfication;
pingCustomer(25,this);
```
