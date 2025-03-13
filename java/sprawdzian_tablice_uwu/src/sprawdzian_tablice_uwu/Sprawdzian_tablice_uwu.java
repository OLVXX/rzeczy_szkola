package sprawdzian_tablice_uwu;
import java.util.Scanner;

public class Sprawdzian_tablice_uwu {

  
    public static void main(String[] args) {
            Scanner scanner = new Scanner(System.in);

        System.out.print("Podaj rozmiar tablicy: ");
        int n = scanner.nextInt();
        
        int[][] tablica = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    tablica[i][j] = i + 1;
                } else {
                    tablica[i][j] = 0;
                }
            }
        }
        System.out.println("Zawartość tablicy:");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(tablica[i][j] + " ");
            }
            System.out.println();
        }

        int suma = 0;
        for (int i = 0; i < n; i++) {
            suma += tablica[i][i];
        }

        System.out.println("Suma elementów na przekątnej: " + suma);
    }
}
