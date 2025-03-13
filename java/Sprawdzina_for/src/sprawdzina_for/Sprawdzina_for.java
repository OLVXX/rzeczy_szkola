package sprawdzina_for;
import java.util.Scanner;
public class Sprawdzina_for {

    public static void main(String[] args) {
     Scanner scan = new Scanner(System.in);
     for(int a = 1; a>=1;){
         a--;
     System.out.println("Podaj n: ");
     int n = scan.nextInt();
     System.out.println("Podaj m: ");
     int m = scan.nextInt();
     if(m>n){
         for(int i=n; i>=m;i++){
         System.out.println(i);}
         System.out.println("Jezeli chcesz kontynuowac nacisnij T");
         string opcja = scan.nextString();
         if(opcja == t || opcja == T ){
             a++;
         }
         else 
             break;
     }
     
         else
         a++;
     }      
     }     
    }    
    

