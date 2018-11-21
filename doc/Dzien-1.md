# Agenda

1. Wspólny kod źródłowy i praca z repozytorium kodu Git DVCS
2. Praca z GitHub: zgłaszanie poprawek, przeglądy kodu źródłowego, akceptowanie zmian, dyskusje online i dokumentowanie kodu, zgłaszanie wewnętrznych (tylko dla działu deweloperskiego) poprawek i ulepszeń kodu źródłowego
3. Separacja modułów danych i odcinanie zbędnych zależności
4. Nazewnictwo i formatowanie kodu

# Plan pracy

1. [Rozgrzewka z GitHub](#rozgrzewka-z-gitbub)
    * Konto GitHub
    * Rozgałęzianie (`fork`) i zgłaszanie zmian (`pull request`)
2. [Konfiguracja Git](#konfiguracja-git)
    * Instalacja i konfiguracja
3. [Praca z Git](#praca-z-git)
    * Klonowanie repozytorium
    * Używanie git-a z linii poleceń

***

## Rozgrzewka z GitHub

* Założenie konta GitHub i sklonowanie repozytorium
![Fork - skolonowanie repozytorium w GitHub](./resources/01-fork-repo.png)
* Edycja pliku przez serwis GitHub
    * plik: [./doc/lista.md](./doc/lista.md)
    * Dopisanie swoich danych (imię, nazwisko, nick)
    * Zatwierdzenie zmian i zgłoszenie aktualizacji `Pull Request`
* Demonstracja synchronizacji i scalenia danych

## Konfiguracja Git

1. Pobranie i instalacja Git dla Windows
    * https://git-scm.com/download/win
	* (opcja) Manager autentykacji dla Git Windows, [więcej informacji ...](https://github.com/Microsoft/Git-Credential-Manager-for-Windows)
2. Stworzenie konfiguracji z danymi użytkownika:
	* Proszę wpisać swoje dane
	```sh
	git config --global user.email "you@example.com"
	git config --global user.name "Your Name"
	```
3. Dodanie aliasów do analizy historii  w formie drzewa
	* Modyfikacja pliku pliku konfiguracyjnego `.gitconfig` (lokalizacja: `C:\Users\{{użytkownik}}`)
	```
	[alias]
		graph1 = log --graph --abbrev-commit --decorate --format=format:'%C(bold blue)%h%C(reset) - %C(bold green)(%ar)%C(reset) %C(white)%s%C(reset) %C(dim white)- %an%C(reset)%C(bold yellow)%d%C(reset)' --all
		graph2 = log --graph --abbrev-commit --decorate --format=format:'%C(bold blue)%h%C(reset) - %C(bold cyan)%aD%C(reset) %C(bold green)(%ar)%C(reset)%C(bold yellow)%d%C(reset)%n''          %C(white)%s%C(reset) %C(dim white)- %an%C(reset)' --all
		lg = !"git graph1"
	```
4. Zmiana edytora
    * Klasyczny notatnik - Notepad
    ```sh
    git config --global core.editor C:\Windows\notepad.exe
    ```
    * Notepad++
    ```sh
    git config --global core.editor "'C:/Program Files (x86)/Notepad++/notepad++.exe' -multiInst -notabbar -nosession -noPlugin"
    ```


## Praca z Git

Nauka i praca z repozytorium Git to bardzo szeroki zakres materiału, któremu można byłoby poświęcić osobne szkolenie. Zajmiemy się podstawowymi zagadnieniami. Na początek artykuł wprowadzający do tematu oraz omówienie podstawowych pojęć: [Artykuł: Wprowadzanie do Git'a](./GitLearn.md).

Komunikacja z repozytorium Git oraz zarządzanie nim wykonuje się z linii poleceń przez program `git.exe` (Windows). Podstawowe polecenia git to:

* `git clone <repo-URL>`
    * Klonuje repozytorium zdalne, czyli pobiera wszystkie rewizje oraz informacje o wskaźnikach zdalnych. Zakłada gałąź główną `master` oraz alias `origin` zawierający adres repozytorium zdalnego.
* `git status`
    * Zwraca informację o niezarejestrowanych zmianach w katalogu roboczym oraz o zmianach zarejestrowanych w poczekalni, które czekają na zatwierdzenie
* `git add .`
    * Dodaje do poczekalni wszystkie zmienione i nowe pliki, które są śledzone przez system wersjonowania. W momencie dodania w poczekalni tworzona jest migawka pliku, która po zatwierdzeniu poleceniem `git commit` zostanie dopisana do nowej rewizji
* `git diff`
    * Pokazuje różnice między poczekalnią a ostatnią zatwierdzoną rewizją
* `git commit`
    * Zatwierdza zmiany zarejestrowane w poczekalni: tworzy nową rewizję w lokalnym repozytorium i dodaje do niej przygotowane w poczekalni migawki plików
* `git push`
    * Wysyła nowe rewizje do repozytorium zdalnego (domyślnie jest to repozytorium o nazwie `origin`). Dodatkowo aktualizuje w zdalnym repozytorium pozycje wskaźników: HEAD i wskaźnika bieżącej gałęzi (domyślnie jest to gałęź master)
* `git pull`
    * Pobiera migawki z repozytorium zdalnego oraz pozycje wskaźników (głowa i bieżąca gałąź) z repozytorium zdalnego.

Synchronizacja z nadrzędnym repozytorium zdalnym (`upstream`). Aktualizacja migawek po zatwierdzeniu, przez właściciela projektu, zgłoszonych zmian. W sytuacji, gdy właściciel zatwierdzając zmiana scala je (`sqash and merge`). Następnie aktualizacja własnego repozytorium zdalnego (`origin`):

```sh
git fetch upstream master
git reset --hard upstream/master
git push --force
```

Więcej informacji o poleceniach git wraz z dokładniejszym wyjaśnieniem w artykule: [Git: Wizualna ściąga](https://marklodato.github.io/visual-git-guide/index-pl.html) (tłumaczenie angielskiego artykułu: "A Visual Git Reference")
