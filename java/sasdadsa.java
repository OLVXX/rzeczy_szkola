import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<String> people = new ArrayList<>();

        while (true) {
            System.out.println("Menu:");
            System.out.println("1. Dodaj osobę");
            System.out.println("2. Wypisz wszystkie osoby");
            System.out.println("3. Znajdź osobę po nazwisku");
            System.out.println("4. Usuń osobę po indeksie");
            System.out.println("5. Usuń osobę po nazwisku");
            System.out.println("6. Zakończ program");

            int wybor = getwybor(scanner);

            switch (wybor) {
                case 1:
                    System.out.print("Podaj nazwisko osoby: ");
                    String name = scanner.next();
                    people.add(name);
                    System.out.println("Osoba dodana.");
                    break;
                case 2:
                    System.out.println("Lista osób:");
                    for (int i = 0; i < people.size(); i++) {
                        System.out.println(i + ": " + people.get(i));
                    }
                    break;
                case 3:
                    System.out.print("Podaj nazwisko do wyszukania: ");
                    String searchName = scanner.next();
                    ArrayList<Integer> indexes = new ArrayList<>();
                    for (int i = 0; i < people.size(); i++) {
                        if (people.get(i).equals(searchName)) {
                            indexes.add(i);
                        }
                    }
                    if (!indexes.isEmpty()) {
                        System.out.println("Osoby znalezione o nazwisku '" + searchName + "' na indeksach: " + indexes);
                    } else {
                        System.out.println("Osoba o podanym nazwisku nie znaleziona.");
                    }
                    break;
                case 4:
                    System.out.print("Podaj indeks osoby do usunięcia: ");
                    int removeIndex = scanner.nextInt();
                    if (removeIndex >= 0 && removeIndex < people.size()) {
                        people.remove(removeIndex);
                        System.out.println("Osoba usunięta.");
                    } else {
                        System.out.println("Nieprawidłowy indeks.");
                    }
                    break;
                case 5:
                    System.out.print("Podaj nazwisko osoby do usunięcia: ");
                    String removeName = scanner.next();
                    int removedCount = 0;
                    for (int i = people.size() - 1; i >= 0; i--) {
                        if (people.get(i).equals(removeName)) {
                            people.remove(i);
                            removedCount++;
                        }
                    }
                    if (removedCount > 0) {
                        System.out.println("Usunięto " + removedCount + " osoby o nazwisku '" + removeName + "'.");
                    } else {
                        System.out.println("Osoba o podanym nazwisku nie znaleziona.");
                    }
                    break;
                case 6:
                    System.out.println("Koniec programu.");
                    scanner.close();
                    System.exit(0);
            }
        }
    }

    private static int getwybor(Scanner scanner) {
        int wybor;
        while (true) {
            System.out.print("Wybierz opcję: ");
            if (scanner.hasNextInt()) {
                wybor = scanner.nextInt();
                if (wybor >= 1 && wybor <= 6) {
                    break;
                } else {
                    System.out.println("Nieprawidłowy wybór. Wybierz opcję od 1 do 6.");
                }
            } else {
                scanner.next();
                System.out.println("Nieprawidłowy wybór. Wybierz opcję od 1 do 6.");
            }
        }
        return wybor;
    }
}
