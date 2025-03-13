import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        int rozmiar = scanner.nextInt();
        int[] tablica =new int[rozmiar];
        for(int i=0;i<rozmiar;i++){
            System.out.println("Podaj liczbe" +(i+1));
            tablica[i]= scanner.nextInt();

        }
        for(int i=0;i<rozmiar;i++){
        System.out.println(tablica[i]);

        }}

    }
