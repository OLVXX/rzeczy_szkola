class KontoBankowe {
    private String wlasciciel;
    private String numerKonta;
    private double saldo;

    public KontoBankowe() {
        this.wlasciciel = "anonymous";
        this.numerKonta = "00000000";
        this.saldo = 0.0;
    }

    public KontoBankowe(String wlasciciel, String numerKonta) {
        this.wlasciciel = wlasciciel;
        this.numerKonta = numerKonta;
        this.saldo = 0.0;
    }

    public void wplata(double kwota) {
        saldo += kwota;
    }

    public void wyplata(double kwota) {
        if (kwota <= saldo) {
            saldo -= kwota;
        } else {
            System.out.println("Brak wystarczających środków na koncie.");
        }
    }

    public void wyswietlInformacje() {
        System.out.println("Właściciel: " + wlasciciel + ", Numer konta: " + numerKonta + ", Saldo: " + saldo + " PLN");
    }

    public static void main(String[] args) {
        KontoBankowe konto1 = new KontoBankowe("Jan Kowalski", "1234567890");
        konto1.wyswietlInformacje();

        konto1.wplata(1000);
        konto1.wyswietlInformacje();

        konto1.wyplata(500.55);
        konto1.wyswietlInformacje();

        KontoBankowe konto2 = new KontoBankowe("Jan Nowak", "111234223");
        konto2.wyswietlInformacje();

        konto2.wplata(300.30);
        konto2.wyswietlInformacje();

        KontoBankowe konto3 = new KontoBankowe();
        konto3.wyswietlInformacje();
    }
}
