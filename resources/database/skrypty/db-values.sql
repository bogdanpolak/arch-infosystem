-- !!! Wymaga wcześniejszego podłączenia do bazy danych !!!

INSERT INTO OP_OPER (nazwa, haslo, imie, nazwisko, status) VALUES ('admin', 'admin', 'Główny', 'Nadzorca', 'A'); -- 101
INSERT INTO OP_OPER (nazwa, haslo, imie, nazwisko, status) VALUES ('kierownik', 'kierownik', 'Jan', 'Niezbędny', 'A'); -- 102
INSERT INTO OP_OPER (nazwa, haslo, imie, nazwisko, status) VALUES ('pracownik', 'pracownik', 'Anna', 'Pracowita', 'A'); -- 103
INSERT INTO OP_OPER (nazwa, haslo, imie, nazwisko, status) VALUES ('ktokolwiek', 'ktokolwiek', 'Gość', '', 'A'); -- 104
INSERT INTO OP_OPER (nazwa, haslo, imie, nazwisko, status) VALUES ('zablokowany', 'zablokowany', 'Julian', 'Zablokowany', 'B'); -- 105
INSERT INTO OP_OPER (nazwa, haslo, imie, nazwisko, status) VALUES ('zawieszony', 'zawieszony', 'Piotr', 'Zawieszony', 'U'); -- 106
INSERT INTO OP_OPER (nazwa, haslo, imie, nazwisko, status) VALUES ('wykreslony', 'wykreslony', 'Andrzej', 'Wykreślony', 'Z'); -- 107

INSERT INTO OP_SLFUN (kod_funsys, opis) VALUES ('BOS$ADM', 'Administrator danych osobowych');
INSERT INTO OP_SLFUN (kod_funsys, opis) VALUES ('BOS$INF', 'Podgląd danych osobowych');
INSERT INTO OP_SLFUN (kod_funsys, opis) VALUES ('BOS$DOD', 'Dodawanie danych osobowych');
INSERT INTO OP_SLFUN (kod_funsys, opis) VALUES ('BOS$MOD', 'Edycja danych osobowych');
INSERT INTO OP_SLFUN (kod_funsys, opis) VALUES ('BOS$USN', 'Usuwanie danych osobowych');
INSERT INTO OP_SLFUN (kod_funsys, opis) VALUES ('PD$ADM', 'Administrator systemu podatkowego');
INSERT INTO OP_SLFUN (kod_funsys, opis) VALUES ('PD$INF', 'Podgląd kont podatkowych');
INSERT INTO OP_SLFUN (kod_funsys, opis) VALUES ('PD$DOD', 'Zakładanie kont podatkowych');
INSERT INTO OP_SLFUN (kod_funsys, opis) VALUES ('PD$MOD', 'Edycja kont podatkowych');
INSERT INTO OP_SLFUN (kod_funsys, opis) VALUES ('PD$USN', 'Usuwanie kont podatkowych');
INSERT INTO OP_SLFUN (kod_funsys, opis) VALUES ('PD$KSG', 'Księgowanie wpłat na kontach podatkowych');

INSERT INTO OP_OPFUN (id_oper, kod_funsys) VALUES (101, 'BOS$ADM');
INSERT INTO OP_OPFUN (id_oper, kod_funsys) VALUES (101, 'PD$ADM');
INSERT INTO OP_OPFUN (id_oper, kod_funsys) VALUES (102, 'BOS$INF');
INSERT INTO OP_OPFUN (id_oper, kod_funsys) VALUES (102, 'BOS$DOD');
INSERT INTO OP_OPFUN (id_oper, kod_funsys) VALUES (102, 'BOS$MOD');
INSERT INTO OP_OPFUN (id_oper, kod_funsys) VALUES (102, 'BOS$USN');
INSERT INTO OP_OPFUN (id_oper, kod_funsys) VALUES (102, 'PD$INF');
INSERT INTO OP_OPFUN (id_oper, kod_funsys) VALUES (102, 'PD$DOD');
INSERT INTO OP_OPFUN (id_oper, kod_funsys) VALUES (102, 'PD$MOD');
INSERT INTO OP_OPFUN (id_oper, kod_funsys) VALUES (102, 'PD$USN');
INSERT INTO OP_OPFUN (id_oper, kod_funsys) VALUES (102, 'PD$KSG');
INSERT INTO OP_OPFUN (id_oper, kod_funsys) VALUES (103, 'BOS$INF');
INSERT INTO OP_OPFUN (id_oper, kod_funsys) VALUES (103, 'PD$INF');

INSERT INTO BO_MAIN (rodzaj_osb, nazwa, nip, kod_kraju, regon, email, telefon, rb_numer, rej_data, rej_oper)
VALUES ('F', 'Banach Stefan', NULL, NULL, NULL, 's.banach@lsm.pl', '609911001', NULL, 'NOW', 101); -- id: 1001
INSERT INTO BO_FIZ (id_osoby, imie, imie_drugie, nazwisko, imie_ojca, imie_matki, pesel, typ_dok_toz, nr_dok_toz, data_ur, miejsce_ur)
VALUES (1001, 'Stefan', NULL, 'Banach', NULL, NULL, NULL, NULL, NULL, NULL, 'Kraków');
INSERT INTO BO_ADRES(id_osoby, typ_adresu, miasto, ulica, dom, lokal, typ_ulicy, kod, poczta, gmina, powiat, wojewodztwo, kraj, rej_data, rej_oper)
VALUES (1001, 'Z', 'Matecznik', 'Funkcjonalna', '9', NULL, 'Ul.', '10-101', 'Matecznik', NULL, NULL, NULL, NULL, 'NOW', 101); -- id: 1001

INSERT INTO BO_MAIN (rodzaj_osb, nazwa, nip, kod_kraju, regon, email, telefon, rb_numer, rej_data, rej_oper)
VALUES ('F', 'Steinhaus Hugo', NULL, NULL, NULL, 'h.steinhaus@lsm.pl', '609911002', NULL, 'NOW', 101); -- id: 1002
INSERT INTO BO_FIZ (id_osoby, imie, imie_drugie, nazwisko, imie_ojca, imie_matki, pesel, typ_dok_toz, nr_dok_toz, data_ur, miejsce_ur)
VALUES (1002, 'Hugo', 'Dyonizy', 'Steinhaus', NULL, NULL, NULL, NULL, NULL, NULL, 'Jasło');
INSERT INTO BO_ADRES(id_osoby, typ_adresu, miasto, ulica, dom, lokal, typ_ulicy, kod, poczta, gmina, powiat, wojewodztwo, kraj, rej_data, rej_oper)
VALUES (1002, 'Z', 'Matecznik', 'Prawdopobona', '13', NULL, 'Ul.', '10-102', 'Matecznik', NULL, NULL, NULL, NULL, 'NOW', 101);  -- id: 1002

INSERT INTO BO_MAIN (rodzaj_osb, nazwa, nip, kod_kraju, regon, email, telefon, rb_numer, rej_data, rej_oper)
VALUES ('F', 'Ulam Stanisław', NULL, NULL, NULL, 's.ulam@lsm.pl', '609912001', NULL, 'NOW', 101); -- id: 1003
INSERT INTO BO_FIZ (id_osoby, imie, imie_drugie, nazwisko, imie_ojca, imie_matki, pesel, typ_dok_toz, nr_dok_toz, data_ur, miejsce_ur)
VALUES (1003, 'Stanisław', 'Marcin', 'Ulam', NULL, NULL, NULL, NULL, NULL, NULL, 'Lwów');
INSERT INTO BO_ADRES(id_osoby, typ_adresu, miasto, ulica, dom, lokal, typ_ulicy, kod, poczta, gmina, powiat, wojewodztwo, kraj, rej_data, rej_oper)
VALUES (1003, 'Z', 'Matecznik', 'Monte Carlo', '51', NULL, 'Ul.', '10-102', 'Matecznik', NULL, NULL, NULL, NULL, 'NOW', 101); -- id: 1003

INSERT INTO BO_MAIN (rodzaj_osb, nazwa, nip, kod_kraju, regon, email, telefon, rb_numer, rej_data, rej_oper)
VALUES ('F', 'Kuratowski Kazimierz', NULL, NULL, NULL, 'k.kuratowski@lsm.pl', '609923002', NULL, 'NOW', 101); -- id: 1004
INSERT INTO BO_FIZ (id_osoby, imie, imie_drugie, nazwisko, imie_ojca, imie_matki, pesel, typ_dok_toz, nr_dok_toz, data_ur, miejsce_ur)
VALUES (1004, 'Kazimierz', NULL, 'Kuratowski', NULL, NULL, NULL, NULL, NULL, NULL, 'Warszawa');
INSERT INTO BO_ADRES(id_osoby, typ_adresu, miasto, ulica, dom, lokal, typ_ulicy, kod, poczta, gmina, powiat, wojewodztwo, kraj, rej_data, rej_oper)
VALUES (1004, 'Z', 'Matecznik', 'Topologiczna', '3', NULL, 'Ul.', '10-101', 'Matecznik', NULL, NULL, NULL, NULL, 'NOW', 101); -- id: 1004

INSERT INTO BO_MAIN (rodzaj_osb, nazwa, nip, kod_kraju, regon, email, telefon, rb_numer, rej_data, rej_oper)
VALUES ('P', 'Agencja Reklam Świetlnych "ARS"', NULL, NULL, NULL, 'buiro@ars-reklamy.com.pl', '691723001', NULL, 'NOW', 101); -- id: 1005
INSERT INTO BO_PRAWNE(id_osoby, nazwa_skr, nazwa_pln, www, numer_krs)
VALUES (1005, 'ARS', 'Agencja Reklam Świetlnych "ARS"', 'ars-reklamy.com.pl', '0000015235');
INSERT INTO BO_ADRES(id_osoby, typ_adresu, miasto, ulica, dom, lokal, typ_ulicy, kod, poczta, gmina, powiat, wojewodztwo, kraj, rej_data, rej_oper)
VALUES (1005, 'Z', 'Warszawa', 'Świetlna', '29', NULL, 'Ul.', '00-091', 'Warszawa', NULL, NULL, NULL, NULL, 'NOW', 101); -- id: 1005

INSERT INTO BO_MAIN (rodzaj_osb, nazwa, nip, kod_kraju, regon, email, telefon, rb_numer, rej_data, rej_oper)
VALUES ('P', 'Skład Farb i Towarów Kolonialnych "ROZMAITOŚCI"', NULL, NULL, NULL, 'buiro@sklad-rozmaitosci.com.pl', '691723001', NULL, 'NOW', 101); -- id: 1006
INSERT INTO BO_PRAWNE(id_osoby, nazwa_skr, nazwa_pln, www, numer_krs)
VALUES (1006, 'ROZMAITOŚCI', 'Skład Farb i Towarów Kolonialnych "ROZMAITOŚCI"', 'sklad-rozmaitosci.com.pl', '0000015235');
INSERT INTO BO_ADRES(id_osoby, typ_adresu, miasto, ulica, dom, lokal, typ_ulicy, kod, poczta, gmina, powiat, wojewodztwo, kraj, rej_data, rej_oper)
VALUES (1006, 'Z', 'Grodzisk', 'Składowa', '18', NULL, 'Ul.', '00-152', 'Grodzisk', NULL, NULL, NULL, NULL, 'NOW', 101); -- id: 1006

INSERT INTO PD_RODZAJE_SKL (id_rodzaju_skl, nazwa, proc_ulgi) VALUES (NULL, 'Działka gruntu', NULL); -- id: 1
INSERT INTO PD_RODZAJE_SKL (id_rodzaju_skl, nazwa, proc_ulgi) VALUES (NULL, 'Budynek mieszkalny', NULL); -- id: 2
INSERT INTO PD_RODZAJE_SKL (id_rodzaju_skl, nazwa, proc_ulgi) VALUES (NULL, 'Budynek pod działalność gospodarczą', NULL); -- id: 3
INSERT INTO PD_RODZAJE_SKL (id_rodzaju_skl, nazwa, proc_ulgi) VALUES (NULL, 'Garaż', 10.0); -- id: 4
INSERT INTO PD_RODZAJE_SKL (id_rodzaju_skl, nazwa, proc_ulgi) VALUES (NULL, 'Las', 25.0); -- id: 5
INSERT INTO PD_RODZAJE_SKL (id_rodzaju_skl, nazwa, proc_ulgi) VALUES (NULL, 'Mieszkanie', 30.0); -- id: 6

INSERT INTO PD_KONTA (id_konta, numer_kw, nier_ulica, nier_dom, nier_lokal, termin_pl, wplata_kwt, wplata_dt)
VALUES (NULL, 'WA1Z/00029533/8', 'Brzozowa', '15', NULL, '2018-09-24', 1539.0, '2018-09-15'); -- id: 1001
INSERT INTO PD_PODATNICY (id_konta, id_osoby, id_adresu, id_adresu_k, udzial_l, udzial_m, status)
VALUES (1001, 1001, 1001, NULL, 1, 2, 'W');
INSERT INTO PD_PODATNICY (id_konta, id_osoby, id_adresu, id_adresu_k, udzial_l, udzial_m, status)
VALUES (1001, 1002, 1002, NULL, 1, 2, 'W');
INSERT INTO PD_SKLADNIKI (id_konta, id_skladnika, id_rodzaju_skl, powierzchnia, udzial, stawka, proc_ulgi)
VALUES (1001, NULL, 1, 800.0, 1.0, 1.50, NULL); -- podatek: 1200.0
INSERT INTO PD_SKLADNIKI (id_konta, id_skladnika, id_rodzaju_skl, powierzchnia, udzial, stawka, proc_ulgi)
VALUES (1001, NULL, 2, 130.0, 1.0, 3.0, 20.0); -- podatek: 312.0
INSERT INTO PD_SKLADNIKI (id_konta, id_skladnika, id_rodzaju_skl, powierzchnia, udzial, stawka, proc_ulgi)
VALUES (1001, NULL, 4, 60.0, 1.0, 0.5, 10.0); -- podatek: 27.0


INSERT INTO PD_KONTA (id_konta, numer_kw, nier_ulica, nier_dom, nier_lokal, termin_pl, wplata_kwt, wplata_dt)
VALUES (NULL, 'WA1Z/00030102/8', 'Brzozowa', '24', NULL, '2018-10-31', 0.0, NULL); -- id: 1002
INSERT INTO PD_PODATNICY (id_konta, id_osoby, id_adresu, id_adresu_k, udzial_l, udzial_m, status)
VALUES (1002, 1001, 1001, NULL, 1, 1, 'W');
INSERT INTO PD_SKLADNIKI (id_konta, id_skladnika, id_rodzaju_skl, powierzchnia, udzial, stawka, proc_ulgi)
VALUES (1002, NULL, 5, 8000.0, 1.0, 0.25, 75.0); -- podatek: 500.0


INSERT INTO PD_KONTA (id_konta, numer_kw, nier_ulica, nier_dom, nier_lokal, termin_pl, wplata_kwt, wplata_dt)
VALUES (NULL, 'WA1Z/00030177/4', 'Konwaliowa', '17', NULL, '2018-12-31', 0.0, NULL); -- id: 1003
INSERT INTO PD_PODATNICY (id_konta, id_osoby, id_adresu, id_adresu_k, udzial_l, udzial_m, status)
VALUES (1003, 1004, 1004, NULL, 1, 1, 'W');
INSERT INTO PD_SKLADNIKI (id_konta, id_skladnika, id_rodzaju_skl, powierzchnia, udzial, stawka, proc_ulgi)
VALUES (1003, NULL, 1, 1200.0, 1.0, 1.50, NULL); -- podatek: 1800.0
INSERT INTO PD_SKLADNIKI (id_konta, id_skladnika, id_rodzaju_skl, powierzchnia, udzial, stawka, proc_ulgi)
VALUES (1003, NULL, 2, 100.0, 1.0, 3.0, NULL); -- podatek: 300.0
INSERT INTO PD_SKLADNIKI (id_konta, id_skladnika, id_rodzaju_skl, powierzchnia, udzial, stawka, proc_ulgi)
VALUES (1003, NULL, 3, 200.0, 1.0, 5.0, 60.0); -- podatek: 400.0
INSERT INTO PD_SKLADNIKI (id_konta, id_skladnika, id_rodzaju_skl, powierzchnia, udzial, stawka, proc_ulgi)
VALUES (1003, NULL, 4, 800.0, 1.0, 0.5, 10.0); -- podatek: 360.0


INSERT INTO PD_KONTA (id_konta, numer_kw, nier_ulica, nier_dom, nier_lokal, termin_pl, wplata_kwt, wplata_dt)
VALUES (NULL, 'WA1Z/00039211/8', 'Jagiellońska', '104', '15', '2018-12-31', 0.0, NULL); -- id: 1004
INSERT INTO PD_PODATNICY (id_konta, id_osoby, id_adresu, id_adresu_k, udzial_l, udzial_m, status)
VALUES (1004, 1003, 1003, NULL, 1, 1, 'W');
INSERT INTO PD_SKLADNIKI (id_konta, id_skladnika, id_rodzaju_skl, powierzchnia, udzial, stawka, proc_ulgi)
VALUES (1004, NULL, 1, 3500.0, 0.00138554, 1.75, NULL); -- podatek: 8.49
INSERT INTO PD_SKLADNIKI (id_konta, id_skladnika, id_rodzaju_skl, powierzchnia, udzial, stawka, proc_ulgi)
VALUES (1004, NULL, 6, 75.35, 1.0, 1.20, 30.0); -- podatek: 63.29

