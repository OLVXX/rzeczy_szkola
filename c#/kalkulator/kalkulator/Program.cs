Console.WriteLine("Podaj pierwszą liczbe");
string a = Console.ReadLine();
double liczba1;
while (!double.TryParse(a, out liczba1))
{
    Console.WriteLine("Podana wartość nie jest prawidłową liczbą. Podaj pierwszą liczbe ponownie:");
    a = Console.ReadLine();
}

Console.WriteLine("Podaj druga liczbe");
string b = Console.ReadLine();
double liczba2;
while (!double.TryParse(b, out liczba2))
{
    Console.WriteLine("Podana wartość nie jest prawidłową liczbą. Podaj druga liczbe ponownie:");
    b = Console.ReadLine();
}

Console.WriteLine("Podaj znak");
string znak = Console.ReadLine();
char znak3 = char.Parse(znak);
while (znak3 != '+' && znak3 != '-' && znak3 != '*' && znak3 != '/' && znak3 != '%')
{
    Console.WriteLine("To nie jest znak operacji matematycznej. Podaj znak ponownie:");
    znak = Console.ReadLine();
    znak3 = char.Parse(znak);
}

double wynik = 0;
switch (znak3)
{
    case '+':
        wynik = liczba1 + liczba2; break;
    case '-':
        wynik = liczba1 - liczba2; break;
    case '*':
        wynik = liczba1 * liczba2; break;
    case '/':
        if (liczba2 != 0)
        {
            wynik = liczba1 / liczba2;
        }
        else
        {
            Console.WriteLine("Nie można dzielić przez zero.");
            return;
        }
        break;
    case '%':
        wynik = liczba1 % liczba2; break;
}

Console.WriteLine($"Wynik: {wynik}");
