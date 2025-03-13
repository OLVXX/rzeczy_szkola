package choinka;
import java.util.Scanner;
public class Choinka {

public static void main(String[] args) {
Scanner scan = new Scanner(System.in);
int b;
System.out.println("Podaj podstawe choinki");
b=scan.nextInt();
  for (int i = 0; i < b; i++) {
   for (int j = 0; j < b - i; j++)
    System.out.print(" ");
   for (int k = 0; k < (2 * i + 1); k++)
    System.out.print("*");
   System.out.println();
  }
 }
}