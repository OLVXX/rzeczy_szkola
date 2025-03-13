/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package pole1;
import java.util.Scanner;
/**
 *
 * @author olafwel
 */
public class Pole1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
           
      
        double a;
        double h;
        Scanner inputScanner = new Scanner(System.in);
        
        System.out.print("Podaj podstawe:");
        a= inputScanner.nextDouble();
    
        System.out.print("Podaj wysokość:");
        h = inputScanner.nextDouble();
        
         if ((a!=0) && (h!=0)){
        double pole =(a*h)/2;
        System.out.println(h + " Pole trojkata wynosi " + pole +" Bok wynosi " + a + " Wysokość wynosi " + h);
        }
         else{
                System.out.println("Taki trójkąt nie może istnieć, upewnij się że wpisałeś odpowiednie dane");
                }
            
    
    
    
}
    }