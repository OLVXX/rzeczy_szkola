with open('sygnaly.txt', 'r') as file:
    data = file.read().splitlines()

# zad1
message = ''.join(word[9] for i, word in enumerate(data) if (i + 1) % 40 == 0 and len(word) >= 10)
print(f'1. {message}')


# zad2
max_unique_letters = 0
word_with_max_unique_letters = ''
for word in data:
    unique_letters = len(set(word))
    if unique_letters > max_unique_letters:
        max_unique_letters = unique_letters
        word_with_max_unique_letters = word

print(f'2. {word_with_max_unique_letters} {max_unique_letters}')



# zad3
def is_within_distance_10(c1, c2):
    return abs(ord(c1) - ord(c2)) <= 10

words_within_distance_10 = []


for word in data:
    is_within_distance = True  


    for i in range(len(word)):
        for j in range(i + 1, len(word)):
            c1 = word[i]
            c2 = word[j]

            
            if abs(ord(c1) - ord(c2)) > 10:
                is_within_distance = False 
                break  

    if is_within_distance:
        words_within_distance_10.append(word)  


for word in words_within_distance_10:
    print(word)


with open('inf_20231024_18.txt', 'w') as file:
    file.write('1. ' + message + '\n')
    file.write('2. ' + word_with_max_unique_letters + ' ' + str(max_unique_letters) + '\n')
    file.write('3. ' + '\n'.join(words_within_distance_10))
