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
4. Artykuł wprowadzający `GitLearn.md` [zobacz](./GitLearn.md).
5. Artykuł praca z gałęziami w Git `WorkingWithBranches.md` [zobacz](./WorkingWithBranches.md)
6. Strategie scalania gałęzi - odpowiedzi ze `stackoverflow.com`
    * [Q: What is the difference between `git merge` and `git merge --no-ff`?](https://stackoverflow.com/questions/9069061/what-is-the-difference-between-git-merge-and-git-merge-no-ff)

***

## Rozgrzewka z GitHub

* Założenie konta GitHub i sklonowanie repozytorium
![Fork - sklonowanie repozytorium w GitHub](./resources/github01-fork-repo.png)
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
* `git commit --amend`
    * Korekta. Scalenie zmian oczekujących aktualnie w poczekalni ze zmianami w ostatniej rewizji. W efekcie powstaje nowa rewizja, która tak jest podpinana, że zastępuje aktualną rewizję. Poza poprawkami w plikach można również poprawić nazwę i komentarz rewizji.
* `git push`
    * Wysyła nowe rewizje do repozytorium zdalnego (domyślnie jest to repozytorium o nazwie `origin`). Dodatkowo aktualizuje w zdalnym repozytorium pozycje wskaźników: HEAD i wskaźnika bieżącej gałęzi (domyślnie jest to gałęź master)
* `git pull`
    * Pobiera migawki z repozytorium zdalnego oraz pozycje wskaźników (głowa i bieżąca gałąź) z repozytorium zdalnego a następnie scala różnice z lokalnym repozytorium

Więcej informacji o poleceniach git wraz z dokładniejszym wyjaśnieniem w artykule: [Git: Wizualna ściąga](https://marklodato.github.io/visual-git-guide/index-pl.html) (tłumaczenie angielskiego artykułu: "A Visual Git Reference")

## Ignorowanie plików

Git sprawdza zawartość pliku `.gitignore`, który jest wykorzystywany w momencie rejestrowania zmian. Pomijane są wszystkie pliki zapisane w `.gitignore` (zapisujemy pełną nazwę pliku lub wzorzec do którego pasuje wiele plików). Ignorować można również katalogi.

**Pliki projektów**

W przypadku projektów RAD Studio poza plikami binarnymi, które łatwo jest wykluczyć trudności powodują pliki projektu (`*.dproj` lub `*.cbproj`) oraz pliki grupy projektów. Są to pliki XML, które są automatycznie zapisywane przez środowisko i programista nie ma kontroli nad ich formatem i zawartością. Niestety środowisko potrafi znacznie zmodyfikować taki plik przy drobnej zmianie. Dlatego warto usuwać ten plik z systemu wersjonowania, z którego korzysta kilku programistów. Jednak nie zawsze jest to możliwe.

Jeśli plik projektu musi być w repozytorium to warto zadbać o to, aby dodawać go tylko, gdy jest to konieczne, a nie przy każdej zmianie. Jednym z rozwiązań jest ręczne przełączanie flagi `Skip-worktree` dla tego pliku. Ustawienie tej flagi spowoduje pomijanie tego pliku, przy kolejnych rejestracjach zmian.

* Ustawienie flagi `Skip-worktree` 
```
git update-index --skip-worktree Project1.cbproj
```

## Praca grupowa i repozytoria zdalne

Typowym schematem pracy w repozytoriach OpenSource jest zgłaszanie zmian, które wprowadzamy najpierw w swoim zdalnym repozytorium projektowym (`origin`). Portale takie GitHub analizują różnice między repozytorium autorskim (źródłowym) a jego klonem (`fork`) i gdy w naszym sklonowanym repozytorium pojawiają się nowe rewizje to możemy w prosty sposób zgłosić żądnie aktualizacji (`pull request`).

![Diagram: schemat pracy z repozytoriami](./resources/github02-pull-request.png)

Nasze repozytorium zdalne domyślnie nazywane jest `origin` i tej nazwy warto się trzymać. Z kolei nadrzędne zdalne repozytorium autorskie nazywane jest w skrócie `upstream`.

Odwoływanie się do repozytorium autorskiego umieszczonego w chmurze możliwe jest za pomocą długie adresu URL. Wpisywanie tego adresu za każdym razem konieczne jest mało wygodne, dlatego definiujemy skrót do tego repozytorium, który nazwiemy `upstream`. Nowy skrót dodajemy poleceniem:

```
git remote add <nazwa-skrótu> <adres-url>
```
Na przykład:

```
git remote add upstream https://github.com/andrea-magni/MARS.git
```

Po zgłoszeniu żądania aktualizacji `pull request` autor przegląda zmiany i decyduje co z nimi zrobić: może poprosić o naniesienie poprawek lub sam dokonuje korekt. Takie poprawki mogą rozciągnąć się na kilka rewizji. Czasem są to ważne zmiany, a czasem drobne literówki. Na koniec autor decyduje w jaki sposób taki pakiet zmian "przenieść" do swojego głównego repozytorium. Mamy tutaj kilka strategi takiego przenoszenia. 

Zazwyczaj autorzy decydują się na scalenie zmian, czyli łączą wszystkie rewizje wchodzące w skład jednego żądania (`pull request`) w jedną, scaloną rewizję. W takim scenariuszu w repozytorium autora (`upstream`) powstaje nowa rewizja, której nie ma ani w moim repozytorium zdalnym (`origin`), ani lokalnym. Stąd konieczne jest pobranie zmian z repozytorium zdalnego `upstream` do naszego lokalnego repozytorium, scalenie różnic i aktualizacja naszego zdalnego repozytorium (`origin`).

Pobranie zmian z repozytorium zdalnego wykonujemy poleceniem:

```
git fetch <repo-url> master
``` 

Polecenie `git fetch` pobiera jedynie nowe migawki oraz nowe rewizje z repozytorium zdalnego i nie scala je z naszą lokalną rewizją bieżącą (`HEAD`). Dzięki temu możemy przeanalizować różnice i dopiero po upewnieniu się co do stanu zmian przełączyć głowę `HEAD` na aktualną wersję stworzoną przez autora.

Pełna procedura aktualizacji repozytorium lokalnego oraz repozytorium zdalnego `origin` na podstawie zmian w repozytorium zdalnym `upstream` wygląda następująco:

```sh
git fetch upstream master
git reset --hard upstream/master
git push --force
```

* Polecenie `git reset --hard` przenosi aktualną gałąź na pozycję `upstream/master` i modyfikuje wszystkie pliki w katalogu roboczym zmieniając je do stanu zgodnego z tą rewizją.
* Polecenie `git push --force` wymusza aktualizację zdalnego repozytorium, w efekcie znikną (będę nie widoczne) nasze drobne korekty i zastąpi je jedna scalona zmiana.

