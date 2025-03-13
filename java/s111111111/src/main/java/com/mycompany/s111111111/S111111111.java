/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.s111111111;
import java.util.Scanner;
/**
 *
 * @author olafwel
 */
public class S111111111 {

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

 
        System.out.print("Podaj liczbę do sprawdzenia: ");
        int liczbaDoSprawdzenia = scanner.nextInt();

        int liczbaWystapien = zliczWystapienia(tablica, liczbaDoSprawdzenia);
        
        System.out.println("Liczba " + liczbaDoSprawdzenia + " występuje " + liczbaWystapien + " razy w tabeli.");

    }

    public static int zliczWystapienia(int[] tablica, int liczba) {
        int liczbaWystapien = 0;
        for (int element : tablica) {
            if (element == liczba) {
                liczbaWystapien++;
            }
        }
        return liczbaWystapien;
    }
}
