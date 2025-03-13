package tabliceuwu;
import java.util.Scanner;
public class Tabliceuwu {

    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int[] anArray;
        System.out.println("Podaj wielkosc tablicy");
        int a = scan.nextInt();
        anArray = new int[a];
        for(int i =0;i<a;i++ ){
             System.out.println("Podaj wartosc komorki nr : "+i);
             int b = scan.nextInt();
             anArray[i]=b;
        }
        
        }
    }
    

