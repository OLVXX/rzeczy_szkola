Console.WriteLine("Podaj ile ma byc ocen w tablicy");
string srozmiar = Console.ReadLine();
int.TryParse(srozmiar, out int rozmiar);
int[] tab1 =  new int[rozmiar];
for (int i = 0; i < tab1.Length; i++)
{
    Console.WriteLine("Podaj "+i+" cyfre");
    string socena = Console.ReadLine();
    int.TryParse(socena, out int ocena);
    tab1[i] = ocena;
   
}
for (int i = 0; i < rozmiar - 1; i++)
{
    Console.Write(tab1[i] + ",");
}
Console.WriteLine(tab1[rozmiar - 1]);
int suma = 0;
for (int i = 0; i < tab1.Length; i++) {
    suma += tab1[i];
}
Console.WriteLine("Srednia ocen wynosi : " + suma / rozmiar);