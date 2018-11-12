# Rejestr zmian

## Zmiany z 2.XI.2018 (Jacek Mąkowski)

1. Rozszerzenie bazy danych o obsługę kont podatkowych
Dodałem cztery nowe tabele:
PD_KONTA - konta podatku od nieruchomości
PD_PODATNICY - podatnicy podatku od nieruchomości (dla danego konta podatkowego)
PD_SKLADNIKI - składniki nieruchomości do obliczenia podatku (dla danego konta podatkowego)
PD_RODZAJE_SKL - słownik rodzajów składników nieruchomości.

    Wysokość podatku jest sumą kwot ze składników. Kwota dla pojedynczego składnika obliczana jest wg wzoru:

    `powierzchnia * udzial * stawka * (1.0 - proc_ulgi/100.0)`

    Obliczona wartość jest zaokrąglana do dwóch miejsc po przecinku.

    Składnik opisywany jest poprzez wskazanie rodzaju składnika ze słownika PD_RODZAJE_SKL. Z wybranego rodzaju składnika można pobrać wartość pola PROC_ULGI jako wartość domyślną inicjującą odpowiadające pole w tabeli PD_SKLADNIKI.

    Podatnicy (tabela PD_PODATNICY) wybierani są razem z adresem (wypełniamy wartości pól ID_OSOBY i ID_ADRESU). Dodatkowo możemy wskazać adres do korespondencji wybranej wcześniej osoby, wpisując jego wartość do pola ID_ADRESU_K.

    Dla każdego podatnika można podać jego udział we współwłasności w postaci ułamka zwykłego (pola UDZIAL_L i UDZIAL_M) oraz określić jego status. Dostępne wartości pola ze statusem:
```
'W' - właściciel/współwłaściciel
'D' - dzierżawca,
'P' - posiadacz,
'S' - spadkobierca,
'I' - inny.
```

2. Okno dialogowe do edycji/podglądu danych pojedynczego konta podatkowego
Okno obsługuje pojedyncze konto podatkowego.
Użyłem zakładek do rozdzielenie składników i podatników.

3. Nowy zestaw uprawnień odnoszących się do operacji na kontach podatkowych
Wprowadziłem do tabeli OP_SLFUN nowe uprawnienia dotyczące operacji na kontach podatkowych. W związku z tym zmodyfikowałem, na szybko, klasę UserInfo tak, aby mogła udzielić odpowiedzi na posiadanie uprawnień w kontekście kont podatkowych (dodałem oznaczenie systemu przez wprowadzenie typu wyliczeniowego System).
