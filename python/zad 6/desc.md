# Mecz (struktury danych)

Dawno temu, w odległej galaktyce, rozegrano mecz w grę, która przypominała siatkówkę. W meczu wystąpiły dwie drużyny: drużyna A i drużyna B. Mecz składał się z 10 000 krótkich rozgrywek. Każda rozgrywka kończyła się wygraną jednej z dwóch drużyn, za którą zwycięska drużyna otrzymywała jeden punkt. \
Plik `data.txt` zawiera zapis wyników kolejnych rozgrywek – jeden wiersz z napisem złożonym z 10 000 znaków A i B. Znak A oznacza, że rozgrywkę wygrała drużyna A, natomiast znak B – że rozgrywkę wygrała drużyna B. \
Napisz program który znajdzie odpowiedzi do poniższych zadań. Odpowiedzi zapisz w pliku `wyniki1.txt`, a każdą z nich poprzedź numerem odpowiedniego zadania.

---

## Subtask_1
Oblicz, ile razy nastąpiła sytuacja, w której rozgrywkę wygrała inna drużyna niż rozgrywkę poprzednią (tzn. dwa kolejne znaki A lub B w opisie meczu się różnią). \
Przykład: Dla napisu ABBBABA odpowiedzią jest 4. \
Natomiast dla pliku `data_przyklad.txt` odpowiedzią jest `1798`. \
Natomiast dla pliku `data.txt` odpowiedzią jest `5030`.

## Subtask_2
Pierwszy set w meczu trwa do pierwszej rozgrywki, po której któraś z drużyn ma co najmniej 1000 punktów za wygranie dotychczasowych rozgrywek, natomiast drużyna przeciwna ma co najmniej 3 punkty mniej. Drużyna, która zdobywa w secie więcej punktów od przeciwnej, wygrywa pierwszego seta. \
Przykład: pierwszy set może się zakończyć wynikami: 1000:500, 997:1000, 1500:1497. Wyniki 900:100, 999:1000, 1500:1500 nie kończą seta. \
Podaj, która drużyna wygrała pierwszego seta i jaki w tym momencie był wynik (liczba zwycięskich rozgrywek drużyny A i liczba zwycięskich rozgrywek drużyny B w pierwszym secie). \
Dla pliku `data_przyklad.txt` odpowiedzią jest: `A 1000:5` \
Dla pliku `data.txt` odpowiedzią jest: `B 1001:1004`

## Subtask_3
Powiemy, że drużyna ma dobrą passę, jeśli wygrywa rozgrywki co najmniej 10 razy z rzędu. Każda dobra passa rozpoczyna się albo na początku meczu, albo bezpośrednio po przegranej rozgrywce. Każda dobra passa kończy się albo z końcem meczu, albo bezpośrednio przed przegraną rozgrywką. \
Podaj łączną liczbę dobrych pass, które miały obie drużyny w meczu. Wyznacz długość najdłuższej dobrej passy i drużynę, która ją osiągnęła. Tylko jedna drużyna miała dobrą passę o tej długości. \
Przykład: w meczu BBBBBBBBBBAABBAAAAAAAAAAABA mamy łącznie 2 dobre passy. Najdłuższą dobrą passę, o długości 11, osiągnęła drużyna A. \
Dla pliku `data_przyklad.txt` odpowiedzią jest: `2 A 1000 (Liczba dobrych pass: 2 Najdłuższa dobra passa: A, 1000 rozgrywek)`. \
Dla pliku `data.txt` odpowiedzią jest: `6 B 15 (Liczba dobrych pass: 6 Najdłuższa dobra passa: B, 15 rozgrywek)`.
