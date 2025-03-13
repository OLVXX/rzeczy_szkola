import random


numbers = [random.randint(35, 80) for _ in range(100)]

sum_of_numbers = sum(numbers)
average = sum_of_numbers / 100

numbers.sort()


numbers_below_35 = [num for num in numbers if num > 35]


percent_below_35 = (len(numbers_below_35) / 100) * 100


with open("H:\przedmioty_szkola\python\wyniki.txt", "w") as file:
    file.write("Wygenerowane liczby: " + str(numbers) + "\n")
    file.write("Liczby poniżej 35: " + str(numbers_below_35) + "\n")
    file.write("Suma liczb: " + str(sum_of_numbers) + "\n")
    file.write("Średnia liczb: " + str(average) + "\n")
    file.write("Procent spełnienia warunku: " + str(percent_below_35) + "%\n")

print("Wyniki zapisane do pliku 'wyniki.txt'")
