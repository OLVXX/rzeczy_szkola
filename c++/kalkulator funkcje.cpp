#include <iostream>
float addition(float a, float b);
float subtraction(float a, float b);
float multiplication(float a, float b);
float division(float a, float b);
int modulo(int a, int b);
void menu();

int main() {
	while (true) {
		menu();
	}
}
float addition(float a, float b){
	return a + b;
}
float subtraction(float a, float b) {
	return a - b;
}
float multiplication(float a, float b) {
	return a * b;
}
float division(float a, float b) {
	return a / b;
}
int modulo(int a, int b) {
	return a % b;
}
void menu() {
	std::cout << " \n Wybierz opcje: \n 1 dodawanie \n 2 odejmowanie \n 3 mnozenie \n 4 dzielenie \n 5 modulo \n 0 wyjscie" << std::endl;
	int opcja;
	std::cin >> opcja;
	float a;
	float b;
	std::cout << "Podaj a : ";
	std::cin >> a;
	std::cout << "Podaj b : ";
	std::cin >> b;
	std::cout << "Wynik: " << std::endl;
	switch (opcja) {
	case 1:
		std::cout << addition(a,b);
		break;
	case 2:
		std::cout << subtraction(a,b);
		break;
	case 3:
		std::cout << multiplication(a,b);
		break;
	case 4:
		std::cout << division(a,b);
		break;
	case 5:
		std::cout << modulo(a,b);
		break;
	}

}

