# Agenda

1. [Dobre praktyki programowania obiektowego](#dobre-praktyki-programowania-obiektowego)
    * Model-View-Controler
    * Znaczenie Prawa Demeter (Law Of Demeter)
    * DRY - Don't Repeat Yourself
    * Automatyczne testy
    * Praca zespołowa
1. [Zasady SOLID](#zasady-solid)
1. Wzorce Gang of Four
1. Wzorce projektowe w C++
1. Automatyczne testowanie kodu. 
    * Testy jednostkowe, autonomizacja kodu (code decoupling) i zaślepki, czyli obiekty symulujące złożone zewnętrzne zależności (mocks).


# Dobre praktyki programowania obiektowego

### Wzorzec MVC 

* Model-View-Controler
* Unikaj kodu spaghetti
    * Nie mieszaj manipulacji na 
* Jedno zadanie realizowane jest przez 3 klasy
    * Dla trywialnych zadań to przerost formy, ale w prawdziwych projektach trywialny kod potrafi się rozrosnąć do ogromnych rozmiarów po uwzględnieniu wszystkich wymagań klienta
* Konieczny mechanizm powiadamiania obiekt => obiekt
* Akcja użytkownika: analizowana jest przez kontroler, który modyfikuje dane i struktury modelu. Z kolei model powiadamia widok o konieczności odświeżenia wyglądu aplikacji
![](./resources/MVC-Process.png)

### Prawo Demeter

LoD = Law of Demeter

[Prezentacja na slideshare.net](https://www.slideshare.net/vladimirtsukur/law-of-demeter-objective-sense-of-style)


### DRY - Don't Repeat Yourself

* Unikaj kopiuj-wklej
* Uogólniaj rozwiązanie - odnajduj podobne wzorce i buduj reużywalne moduły
* W metodach używaj mniej niż 5 wyrażeń warunkowych IF / WHILE
* Separacja logiki
* Wydzielaj logikę na zewnątrz
* Staraj się wstrzykiwać wszelkie zależności do klasy (Prawo Demeter)

### Automatyczne testowanie kodu

* Testuj kod często
* Postaraj się, aby robiły to za Ciebie automaty
    * Testy jednostkowe - DUnit
    * Testy integracyjne - DUnit
    * Testy akceptacyjne - Ranorex Studio
* Zostań mistrzem testów jednostkowych eksperymentując z TDD
    * cykl: prosty test - kod spełniający test - refaktoring

### Praca zespołowa

* Używaj aktywnie repozytorium (to nie tylko kopia zapasowa)
    * Przy całodziennym kodowaniu - min. 10 rewizji (commit-ów)
* Przy całodziennym kodowaniu - min. 10 rewizji (commit-ów)
* Przeglądy kodu źródłowego
* Praca w parach
* Losowe przydzielanie naprawy bug-ów (zobacz https://www.codetriage.com)
* Losowe przydzielanie recenzenta do nowo zgłoszonej paczki zmian 

### Zapachy kodu

Nie programuj zawsze w ten sam sposób. Ucz się i eksperymentuj z nowymi sposobami kodowania.  Naucz się rozpoznawać zapachy kodu: kiedy śmierdzi, a kiedy ma miły zapach.

Lektury:

* Książka: Refactoring - Improving the Design of Existing Code
   * autorzy: Martin Fowler, Kent Beck, John Brant, William Opdyke, Don Roberts, Erich Gamma
   * [Tłumaczenie na polski (Helion)](https://helion.pl/ksiazki/refaktoryzacja-ulepszanie-struktury-istniejacego-kodu-martin-fowler-kent-beck-john-brant-william-opdy,refukv.htm)


# Zasady SOLID

![(c) Mohit Rajput - mohitrajput987 Apr 30 '17 https://dev.to/mohitrajput987/coding-best-practices-part-1-naming-conventions--class-designing-principles](https://res.cloudinary.com/practicaldev/image/fetch/s--VIyIhNNs--/c_limit%2Cf_auto%2Cfl_progressive%2Cq_auto%2Cw_880/https://s11.postimg.org/r5n293c4z/SOLID.jpg)

1. SRP = Single Responsibility Principle
    * Klasa powinna być odpowidzialna za jedną rzecz
2. OCP = Open/Close Principle
    * Klasa musi być otwarta na rozbudowę, ale zamknięta na poprawę dobrego kodu
    * Podejrzane: wielopoziomowe if-ów / casów
    * Rozwiązania OOP: abstrakcja, polimorfizm, fabryki
    * Użycie wzorca Fabryki Abstrakcyjnej
        * dostęp do wielu fabryk przez jeden interfejs (klasę abstrakcyjną)
        * dostęp do wyprodukowanych obiektów przez wspólny interfejs lub klasę abstrakcyjną
        * [przykład w C++](https://sourcemaking.com/design_patterns/abstract_factory/cpp/before-after)
        * [przykład w C# / Java](https://refactoring.guru/design-patterns/abstract-factory)
        * [przykład w Delphi](https://www.devfields.com/design-patterns-abstract-factory-pattern/)
3. LSP = Liskov Substition Principle
    * Poprawnie zbudowane drzewo dziedziczenia nie wymaga nadpisywania metod ojca, w celu poprawnego działania algorytmu
    * ```TKwadrat != class(TProstokąt)```
        * zobacz jak działa metoda WyliczPole
    * poprawnie: 
        ```
        TKwadrat = class(TFigure)
        TProstokąt = class(TFigure)
        ```
4. ISP = Interface Segreation Principle
    * Podziel interfejsy na mniejsze (spójne dziedzinowo)
5. DIP = Dependency Invertion Principle
    * Klasy z dwóch różnych warstw separuj interfejsami
    * Przykład: Klasy dziedzinowe (realizujące funkcjonalność) oraz klasy składujące dane (zbiory danych).
    * Jeśli klasa warstwy wyższej tworzy obiekty warstwy niższej to można zastosować: IoC = Inversion of Control
    * Trzech muszkieterów: DIP, IoC, DI (Dependency Injection)
