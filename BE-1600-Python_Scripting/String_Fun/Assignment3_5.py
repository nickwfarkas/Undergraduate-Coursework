def count_vowels(word):
    word = word.lower()
    vowels = "aeiou"
    count = 0
    for c in range(len(word)):
        for i in range(len(vowels)):
            if(word[c] == vowels[i]):
                count+=1
    return count

def count_consonants(word):
    word = word.lower()
    cons = "bcdfghjklmnpqrstvwxyz"
    count = 0
    for c in range(0,len(word)):
        for i in range(0,len(cons)):
            if(word[c] == cons[i]):
                count+=1
    return count

userInput = input("Enter a string: ")
print("The string you entered includes {} vowels and {} consonants"
      .format(count_vowels(userInput), count_consonants(userInput)))
