# CCC '05 J5 - Bananas

import sys

input = sys.stdin.readline


def find_s(t: str) -> int:
    b = 0
    for i in range(len(t)):
        if t[i] == "B":
            b += 1
        elif t[i] == "S":
            if b == 1:
                return i
            b -= 1

    return -1


def monkey(t: str) -> bool:
    if len(t) == 0:
        return False

    if t[0] == "B":
        last_s = find_s(t)
        if last_s == -1:
            return False

        if last_s == len(t) - 1:
            return monkey(t[1:-1])

        if t[last_s + 1] == "N":
            return a_word(t[: last_s + 1]) and monkey(t[last_s + 2 :])

        return False

    if "N" in t:
        sub = t.split("N", 1)
        return a_word(sub[0]) and monkey(sub[1])

    return a_word(t)


def a_word(t: str) -> bool:
    if len(t) == 1:
        return t == "A"

    if len(t) == 0:
        return True

    if t[0] == "B":
        last_s = find_s(t)
        if last_s == -1:
            return False

        return monkey(t[1:last_s])

    return False


while True:
    word = input()
    if word == "X\n":
        break

    print("YES" if monkey(word[:-1]) else "NO")
