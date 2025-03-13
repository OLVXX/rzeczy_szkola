Random rnd = new Random();
int day = rnd.Next(1, 8);
Console.WriteLine($"Your random number is {day}");

switch (day)
{
    case 1:
        Console.WriteLine("Monday");
        break;
    case 2:
        Console.WriteLine("Tuesday");
        break;
    case 3:
        Console.WriteLine("Wednesday");
        break;
    case 4:
        Console.WriteLine("Thursday");
        break;
    case 5:
        Console.WriteLine("Friday");
        break;
    case 6:
        Console.WriteLine("Saturday");
        break;
    case 7:
        Console.WriteLine("Sunday");
        break;
}

switch (day)
{
    case >= 1 and <= 5:
        Console.WriteLine("Workday");
        break;
  
    case >5:
        Console.WriteLine("Weekend");
        break;
}
