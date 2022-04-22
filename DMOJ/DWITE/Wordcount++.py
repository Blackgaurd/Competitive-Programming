# DWITE '08 R3 #2 - Wordcount++

punctuations = "!()-[]{};:'\"\,<>./?@#$%^&*_~"

for x in range(5):
    text = input()
    for punc in punctuations:
        text = text.replace(punc, " ")
    text = text.split()
    count = sum(len(text[word]) > 3 for word in range(len(text)))
    print(count)
