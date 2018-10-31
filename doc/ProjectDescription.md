# Opis projektu

Aplikacja na wewnętrze potrzeby szkolenia szkolenie. Zapisana w folderze `projects`

## Cel

Aplikacja 'Klienci' obsługuje prostą wersję rejestru klientów. Pozwala na wykonywania operacji:
- dodania nowego klienta do rejestru,
- aktualizacji danych klienta w rejestrze,
- usunięcia danych klienta z rejestru,
- przeglądania rejestru klientów.

## Logowanie

Otwarcie rejestru wymaga zalogowania operatora. Zalogowanie następuje przez dwukrotne kliknięcie na kontrolce wewnątrz ramki 'Zalogowany operator'. Po udanym zalogowaniu zostają udostępnione wszystkie przyciski na oknie dialogowym. Do wykonania poszczególnych czynności operator musi posiadać odpowiednie uprawnienia. Są one sprawdzane tuż przed wykonaniem danej czynności.

## Baza danych

Aplikacja działa na bazie Firebird. Do otwarcia załączone bazy należy użyć serwera 32 bitowego w najnowszej wersji 2.5 **Uwaga! wersja 3.0 nie będzie działać**.

Tabele składające się na rejestr klientów:
| Nazwa | Opis |
| --- | --- |
| OP_OPER | operatorzy |
| OP_SLFUN | słownik uprawnień |
| OP_OPFUN | uprawnienia przyznane operatorm |
| BO_MAIN | główna tabela z danymi klienta |
| BO_FIZ | dane klientów będącymi osobami fizycznymi |
| BO_PRAWNE | dane klientów będącymi przedsiębiorstwami |
| BO_ADRES | dane adresowe klientów |


## Pliki tworzące aplikację

* fm_main_form 
   - główne okno aplikacji
* dm_database_module 
   - główny moduł danych aplikacji; dane dostępowe do bazy wpisane są bezpośrednio w komponent połączeniowy ConnectionDB; moduł udostępnia funkcję logowania operatora i przechowuje dane zalogowanego operatora
* dm_person_module
   - moduł danych udostępniający dane klientów będących osobami fizycznymi
* fm_login_dlg
   - okno dialogowe do logowania operatora
* fm_person_dlg
   - okno dialogowe do manipulowania danymi klienta, który jest osobą fizyczną
* fm_seek_client_dlg
   - okno dialogowe do wyszukiwania danych klientów na podstawie ich identyfikatora lub nazwy
* fm_select_client_dlg
   - okno dialogowe do wybrania klienta z dostarczonej listy; używane, gdy wyszukiwanie klientów da w odpowiedzi więcej niż jeden rekord
* fm_browser_dlg
   - okno dialogowe do przeglądania rejestru klientów; z poziomu okna można modyfikować
   rejestr dodając, edytując i usuwając poszczególnych klientów
* user_info
   - definicja klasy z informacją o zalogowanym operatorze (użytkowniku).
