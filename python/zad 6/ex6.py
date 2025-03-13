def read_data(file_name):
    with open(file_name, 'r') as file:
        data = file.read().strip()
    return data

def subtask_1(data):
    return sum(a != b for a, b in zip(data, data[1:]))

def subtask_2(data):
    wynik_a = wynik_b = 0
    for i in data:
        if i == 'A':
            wynik_a += 1
        else:
            wynik_b += 1
        if max(wynik_a, wynik_b) >= 1000 and abs(wynik_a - wynik_b) >= 3:
            return 'A' if wynik_a > wynik_b else 'B', wynik_a, wynik_b

def subtask_3(data):
    dobre_passy = []
    aktualna_druzyna = data[0]
    aktualna_passa = 0

    for i in data:
        if i == aktualna_druzyna:
            aktualna_passa += 1
        else:
            if aktualna_passa >= 10:
                dobre_passy.append((aktualna_druzyna, aktualna_passa))
            aktualna_druzyna = i
            aktualna_passa = 1

    if aktualna_passa >= 10:
        dobre_passy.append((aktualna_druzyna, aktualna_passa))

    longest_pass = max(dobre_passy, key=lambda x: x[1])
    return len(dobre_passy), longest_pass

def main():
    data = read_data('data.txt')
    
    # Subtask 1
    result_1 = subtask_1(data)
    with open('wyniki.txt', 'a') as file:
        file.write(f"Subtask_1: {result_1}\n")

    # Subtask 2
    result_2 = subtask_2(data)
    with open('wyniki.txt', 'a') as file:
        file.write(f"Subtask_2: {result_2}\n")

    # Subtask 3
    result_3 = subtask_3(data)
    with open('wyniki.txt', 'a') as file:
        file.write(f"Subtask_3: Liczba dobrych pass: {result_3[0]} Najdłuższa dobra passa: {result_3[1][0]}, {result_3[1][1]} rozgrywek\n")

if __name__ == "__main__":
    main()
