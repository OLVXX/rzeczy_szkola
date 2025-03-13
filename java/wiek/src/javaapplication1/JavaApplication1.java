/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;
import java.util.Scanner;

/**
 *
 * @author olafwel
 */
public class JavaApplication1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);        
        
        int a=2022;
    int b = input.nextInt();
    int age= a-b;
    
    if (age>=18){
    
 System.out.println("Jestes osoba pelnoletnia.");
    }
        else System.out.println("Jestes osoba nie pelnoletnia.");
    }
    
}
