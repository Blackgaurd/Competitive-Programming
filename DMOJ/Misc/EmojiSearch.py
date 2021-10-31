# Emoji Search
# one liner lol

[print(i[1:-1]) for i in __import__("re").findall(":[a-zA-Z0-9 ]*:", input())]