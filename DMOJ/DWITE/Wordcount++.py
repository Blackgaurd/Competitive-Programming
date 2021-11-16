# DWITE '08 R3 #2 - Wordcount++

punctuations = """!()-[]{};:'"\,<>./?@#$%^&*_~"""

for x in range(5):
    text = input()
    for punc in punctuations:
        text = text.replace(punc, " ")
    text = text.split()
    count = 0
    for word in range(0, len(text)):
        if len(text[word]) > 3:
            count += 1
    print(count)
