W pliku dane.txt znajduje się 200 wierszy. Każdy wiersz zawiera 320 liczb naturalnych z przedziału od 0 do 255, oddzielonych znakami pojedynczego odstępu (spacjami). Przedstawiają one jasności kolejnych pikseli czarno-białego obrazu o wymiarach 320 na 200 pikseli (od 0 – czarny do 255 – biały).

Napisz program, który da dpowiedzi do poniższych zadań. Odpowiedzi zapisz w pliku `wyniki.txt`, a każdą odpowiedź poprzedź numerem oznaczającym odpowiednie zadanie.

**Uwaga**: plik przyklad.txt zawiera dane przykładowe spełniające warunki zadania (obraz ma takie same rozmiary). Odpowiedzi dla danych z pliku przyklad.txt są podane pod poleceniami.

***

## Zadanie_1
Podaj jasność najjaśniejszego i jasność najciemniejszego piksela. \
Dla danych z pliku przyklad.txt wynikiem jest 255 (najjaśniejszy) i 0 najciemniejszy.

## Zadanie_2
Podaj, ile wynosi najmniejsza liczba wierszy, które należy usunąć, żeby obraz miał pionową oś symetrii. Obraz ma pionową oś symetrii, jeśli w każdym wierszu i-ty piksel od lewej strony przyjmuje tę samą wartość, co i-ty piksel od prawej strony, dla dowolnego 1 ≤ i ≤ 320. \
Dla danych z pliku przyklad.txt wynikiem jest 3

## Zadanie_3
Sąsiednie piksele to takie, które leżą obok siebie w tym samym wierszu lub w tej samej kolumnie. Dwa sąsiednie piksele nazywamy kontrastującymi, jeśli ich wartości różnią się o więcej niż 128. Podaj liczbę wszystkich takich pikseli, dla których istnieje przynajmniej jeden kontrastujący z nim sąsiedni piksel. \
Dla danych z pliku przyklad.txt wynikiem jest 5.

## Zadanie_4
Podaj długość najdłuższej linii pionowej (czyli ciągu kolejnych pikseli w tej samej kolumnie obrazka), złożonej z pikseli tej samej jasności. \
Dla danych z pliku przyklad.txt wynikiem jest 198.

## Zadanie_5
Podaj wartość piksela, który występuje najwięcej i najmniej razy.
