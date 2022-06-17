def word_count(words):
    print("'"+words+"' -> ",end='')
    words += " "
    count = 0
    for i in range(len(words)):
        if(('!' <= words[i] <= '~') and words[i+1] == ' '):
            count+=1
    return count

print(word_count("hello"))
