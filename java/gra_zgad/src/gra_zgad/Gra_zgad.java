package gra_zgad;

import java.util.Random;
import java.util.Scanner;

/**
 *
 * @author olafwel
 */
public class Gra_zgad {
public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    Random rand = new Random();    
    System.out.println("Wybierz zasięg w którym będą generować się liczby");
    int zasieg = scan.nextInt();
        int n = rand.nextInt(zasieg);
        System.out.println("Podaj ile chcesz mieć prób");
        int proby = scan.nextInt();
        
        
        for ( int i = 1; i<=proby; i++){
        System.out.println("Zgadnij liczbę");
        int strzal = scan.nextInt();
        if (strzal != n && strzal>n){
            System.out.println("Źle liczba jest mniejsza");}
            else if (strzal !=n && strzal < n){
                 System.out.println("Źle liczba jest większa");               
        }
            else {
            System.out.println("Zgadłeś liczbą do zgadniecia było : " + n + " zgadłeś za próbą nr : " + i);
            break;
            }
            if(i>proby){
                 System.out.println("Przegrałeś, przekroczyłeś ilośc prób");
            }
        }
}
    
}
