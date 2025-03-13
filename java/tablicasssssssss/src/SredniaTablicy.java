import java.util.Scanner;

public class SredniaTablicy {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Podaj rozmiar tablicy: ");

        int rozmiar = scanner.nextInt();

        int[] tablica = new int[rozmiar];

        for (int i = 0; i < rozmiar; i++) {
            System.out.print("Podaj liczbę #" + (i + 1) + ": ");
            tablica[i] = scanner.nextInt();
        }

        double suma = 0;
        for (int liczba : tablica) {
            suma += liczba;
        }
        double srednia = suma / rozmiar;

        System.out.println("Średnia liczb w tabeli wynosi: " + srednia);

    }
}
