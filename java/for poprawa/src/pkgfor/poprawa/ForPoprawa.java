
package pkgfor.poprawa;
import java.util.Scanner;
public class ForPoprawa {
    
    public static void main(String[] args) {
        
        Scanner scan =new Scanner(System.in);
        int suma=0;
        int dodatnie = 0;
        int ujemne=0;
        
        
        for(int i =1;i!=0;){
        System.out.println("Podaj liczbę:");
        i = scan.nextInt();
        suma = suma + i;
         System.out.println("Jezeli chesz zakonczyc program nacisnij 0");
        if(i > 0){
        dodatnie++;
                }
        if(i < 0){
        ujemne++;       
        }
        
        }
        suma=suma-1;
        System.out.println("Suma wynosi:"+ suma);
        
        System.out.println("Liczy dodatnie zostaly podane tyle razy : " + dodatnie);
        
        System.out.println("Liczy ujemne zostaly podane tyle razy : "+ ujemne);
        

        
        
        
        
    }
    
}
