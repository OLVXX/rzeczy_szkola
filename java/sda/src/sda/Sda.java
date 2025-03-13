package sda;
import java.util.Scanner;
public class Sda {
    public static void main(String[] args) {
   Scanner scan = new Scanner(System.in); 
   int miesiac;
   miesiac = scan.nextInt();
   int dzien_tygodnia;
   dzien_tygodnia = scan.nextInt();
   switch(miesiac){
       case 1:
           System.out.println("Styczeń");
       case 2:
           System.out.println("Luty");
       case 3:
           System.out.println("Marzec");
        case 4:
           System.out.println("Kwiecień");   
        case 5:
           System.out.println("Maj");
        case 6:
           System.out.println("Czerwiec");
        case 7:
           System.out.println("Lipiec");
        case 8:
           System.out.println("Sierpień");
        case 9:
           System.out.println("Wrzesień");
        case 10:
           System.out.println("Październik");
        case 11:
           System.out.println("Listopad");
        case 12:
           System.out.println("Grudzień");
       
   }
    }
    
}
