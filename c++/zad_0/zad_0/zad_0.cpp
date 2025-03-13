#include <iostream>
#include <cstdlib>

int main()
{
	const int size = 1000;
	int array[size];
	srand(2137);
	for (int i = 0; i < size; i++)
	{
		if (i % 3 == 0)
		{
			array[i] = rand();
		}
		else
		{
			array[i] = -1;
		}
	}

	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += array[i];
	}

	std::cout << "Suma wszystkich elementow: " << sum << std::endl;

	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i] >= 6776 && array[i] <= 10101)
		{
			count++;
		}
	}

	std::cout << "Liczba miedzy 6776, a 10101: " << count << std::endl;

	int min = 10101, max = 6776;
	for (int i = 0; i < size; i++)
	{
		if (array[i] > max && array[i] != -1)
		{
			max = array[i];
		}
		if (array[i] < min && array[i] != -1)
		{
			min = array[i];
		}
	}

	std::cout << "Najmniejsza wartosc: " << min << std::endl;
	std::cout << "Najwieksza wartosc: " << max << std::endl;

	return 0;
}