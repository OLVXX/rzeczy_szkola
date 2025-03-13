## Zadanie

W ramach projektu `ESA` naukowcom udało się odczytać sygnały radiowe pochodzące z przestrzeni kosmicznej. Po wstępnej obróbce zapisali je do pliku sygnaly.txt.
W pliku sygnaly.txt znajduje się 1000 wierszy. Każdy wiersz zawiera jedno niepuste słowo złożone z wielkich liter alfabetu angielskiego. Długość jednego słowa nie przekracza 100 znaków.

Napisz program w języku programowania `python`, który pomoże uzyskać odpowiedzi do poniższych zadań. Odpowiedzi zapisz w pliku `inf_20231024_18.txt`, a każdą odpowiedź poprzedź numerem oznaczającym dpowiednie zadanie.

Plik `przyklad.txt`` zawiera dane przykładowe spełniające warunki zadania. Odpowiedzi dla danych z pliku `przyklad.txt`` są podane pod pytaniami.

1. Naukowcy zauważyli, że po złączeniu dziesiątych liter co czterdziestego słowa (zaczynając od słowa czterdziestego) otrzymamy pewne przesłanie. Wypisz to przesłanie.
    - Uwaga: Każde co czterdzieste słowo ma co najmniej 10 znaków.
    - Dla danych z pliku przyklad.txt wynikiem jest: **NIECHCIMATURAPROSTABEDZIE**
1. Znajdź słowo, w którym występuje największa liczba różnych liter. Wypisz to słowo i liczbę występujących w nim różnych liter. Jeśli słów o największej liczbie różnych liter jest więcej niż jedno, wypisz pierwsze z nich pojawiające się w pliku z danymi.
    - Do tego typu zadań najlepiej zapoznać się z gotową strukturą danych `set (zbiór)`
    - Dla danych z pliku przyklad.txt wynikiem jest: **AKLMNOPRSTWZA 12**
1. W tym zadaniu rozważmy odległość liter w alfabecie – np. litery A i B są od siebie oddalone o 1, A i E o 4, F i D o 2, a każda litera od siebie samej jest oddalona o 0. Wypisz wszystkie słowa, w których każde dwie litery oddalone są od siebie w alfabecie co najwyżej o 10. Słowa wypisz w kolejności występowania w pliku sygnaly.txt, po jednym w wierszu.
    - Do tego typu zadań najlepiej zapoznać się `tablicą ASCII` oraz funkcją `ord`
    - Na przykład CGECF jest takim słowem, ale ABEZA nie jest (odległość A – Z wynosi 25)
    - Dla danych z pliku przyklad.txt wynikiem jest :
        ```
        AAAAAAAAAI
        AAAAAAAAAE
        AAAAAAAAAC
        AAAAAAAAAH
        AAAAAAAAAC
        AAAAAAAAAI
        AAAAAAAAAA
        BB
        AAAAAAAAAA
        AAAAAAAAAA
        AAAAAAAAAB
        AAAAAAAAAE
        AAAAAAAAAD
        AAAAAAAAAI
        AAAAAAAAAE
        ```
