package pkgfor.cw;
import java.util.Scanner;
public class ForCw {
    public static void main(String[] args) {
        
        Scanner scan = new Scanner(System.in);
         System.out.println("Podaj swoje imie");
         String imie;
         imie =scan.next();
        System.out.println("Podaj ile razy ma zostać wyświetlone twoje imie");
        int ile =scan.nextInt();
        for(int i = 0;i<ile;i++ ){
        System.out.println(imie);
        }
    }
    
}
