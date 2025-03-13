import java.util.Scanner;
import java.util.Random;
public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        Random rand = new Random();
            System.out.println("Wybierz: \n 1 kamien \n 2 papier \n 3 nozyce");
            int wybor = scan.nextInt();
            int bot = rand.nextInt(2);
            if (wybor == bot + 1) {
                System.out.println("Remis obaj wybraliscie to samo");
            }
            if (wybor == 1 && bot == 2) {
                System.out.println("Wygrales bot dal nozyce");
            }
            if (wybor == 1 && bot == 1) {
                System.out.println("Przegrales bot dal papier");
            }
            if (wybor == 2 && bot == 0) {
                System.out.println("Wygrales bot dal kamien");
            }
            if (wybor == 2 && bot == 2) {
                System.out.println("Przegrales bot dal nozyce");
            }
            if (wybor == 3 && bot == 1) {
                System.out.println("Wygrales bot dal papier");
            }
            if (wybor == 3 && bot == 0) {
                System.out.println("Przegrales bot dal kamien");
            }
        }
    }
