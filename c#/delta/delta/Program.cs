Console.WriteLine("Podaj dystans");
string sodleglosc = Console.ReadLine();
int.TryParse(sodleglosc, out int odleglosc);
while (odleglosc < 0)
{
    Console.WriteLine("Odleglosc nie może być ujemna, podaj liczbe ponownie");
    sodleglosc = Console.ReadLine();
    int.TryParse(sodleglosc, out odleglosc);
}

Console.WriteLine("Podaj jednostke w jakiej jest zapisana odleglosc \n 1. km \n 2. m \n 3. mile \n 4. stopy");
string jednostka = Console.ReadLine();
switch (jednostka)
{
    case "1":
        odleglosc *= 1000;
        break;
    case "2":
        // odleglosc w metrach
        break;
    case "3":
        odleglosc *= 1600;
        break;
    case "4":
        odleglosc = (int)(odleglosc * 0.3);
        break;
    default:
        Console.WriteLine("Nieznana jednostka");
        return;
}

Console.WriteLine("Podaj jednostke na jaka chcesz przekonwertowac odleglosc \n 1. km \n 2. m \n 3. mile \n 4. stopy");
string jednostkaDocelowa = Console.ReadLine();
double odlegloscDocelowa = odleglosc;
switch (jednostkaDocelowa)
{
    case "1":
        odlegloscDocelowa /= 1000;
        break;
    case "2":
        // odleglosc w metrach
        break;
    case "3":
        odlegloscDocelowa /= 1600;
        break;
    case "4":
        odlegloscDocelowa /= 0.3;
        break;
    default:
        Console.WriteLine("Nieznana jednostka");
        return;
}

Console.WriteLine($"Odleglosc wynosi: {odlegloscDocelowa}");
