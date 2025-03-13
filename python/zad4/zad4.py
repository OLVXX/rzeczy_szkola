from collections import defaultdict

# Zadanie_0
def zle_wyniki(filename, output_file):
    with open(filename, 'r') as file:
        lines = file.readlines()
    invalid_count = 0

    for line in lines:
        components = line.split()
        if len(components) != 4:
            invalid_count += 1
        else:
            a, b, operation, result = components
            try:
                a = int(a)
                b = int(b)
                result = int(result)
                if operation == '+':
                    if a + b != result:
                        invalid_count += 1
                elif operation == '-':
                    if a - b != result:
                        invalid_count += 1
                elif operation == '*':
                    if a * b != result:
                        invalid_count += 1
                elif operation == '/':
                    if b != 0 and a / b != result:
                        invalid_count += 1
                elif operation == '%':
                    if b != 0 and a % b != result:
                        invalid_count += 1
                else:
                    invalid_count += 1
            except ValueError:
                invalid_count += 1

    output_file.write(f"Zadanie_0: Liczba wierszy z niepoprawnym wynikiem: {invalid_count}\n")

# Zadanie_1
def ilosc_operacji(filename, output_file):
    with open(filename, 'r') as file:
        lines = file.readlines()
    operation_count = defaultdict(int)

    for line in lines:
        components = line.split()
        if len(components) == 4:
            operation = components[2]
            operation_count[operation] += 1

    output_file.write("Zadanie_1: Liczba wystąpień operacji arytmetycznych:\n")
    for operation, count in operation_count.items():
        output_file.write(f"{operation}: {count} wystąpień\n")

# Zadanie_2
def ilosc_specjalnych_liczb(filename, output_file):
    with open(filename, 'r') as file:
        lines = file.readlines()
    special_number_count = 0

    for line in lines:
        components = line.split()
        if len(components) == 4:
            a, b, _, result = components
            if len(a) >= 3 and len(b) >= 3 and len(result) >= 3:
                if a[0] == '7' and a[-1] == '1' and b[0] == '1' and b[-1] == '2':
                    special_number_count += 1

    output_file.write(f"Zadanie_2: Liczba liczb spełniających warunek: {special_number_count}\n")

# Zadanie_3
def get_unique_results(filename):
    with open(filename, 'r') as file:
        lines = file.readlines()
    unique_results = set()

    for line in lines:
        components = line.split()
        if len(components) == 4:
            result = components[3]
            unique_results.add(int(result))

    unique_results = sorted(list(unique_results))
    return unique_results

# Zadanie_4
def ilosc_wyjatkow(filename, output_file):
    unique_results = get_unique_results(filename)
    result_count = defaultdict(int)

    for result in unique_results:
        with open(filename, 'r') as file:
            lines = file.readlines()
            for line in lines:
                components = line.split()
                if len(components) == 4:
                    if int(components[3]) == result:
                        result_count[result] += 1

    output_file.write("Zadanie_4: Liczba wystąpień unikalnych wartości wyników:\n")
    for result, count in result_count.items():
        output_file.write(f"{result}: {count} wystąpień\n")

# Zadanie_5
def zapisz_wyniki(filename, output_filename):
    unique_results = get_unique_results(filename)
    with open(output_filename, 'w') as output_file:
        for result in unique_results:
            output_file.write(str(result) + '\n')

if __name__ == '__main__':
    input_filename = 'dane.txt'
    output_filename = 'answers.txt'

    with open(output_filename, 'w') as output_file:
        # Zadanie_0
        zle_wyniki(input_filename, output_file)

        # Zadanie_1
        ilosc_operacji(input_filename, output_file)

        # Zadanie_2
        ilosc_specjalnych_liczb(input_filename, output_file)

        # Zadanie_3 (wysyła wyniki bezpośrednio do pliku 'answers.txt')
        zapisz_wyniki(input_filename, output_filename)

        # Zadanie_4
        ilosc_wyjatkow(input_filename, output_file)
