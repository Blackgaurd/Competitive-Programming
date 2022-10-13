# CCC '22 J3 - Harp Tuning

import re

instructions = input()

matches = re.findall(r"[A-Z]+[+|-]\d+", instructions)
for match in matches:
    if "+" in match:
        letters, turns = match.split("+")
        print(letters, "tighten", turns)
    elif "-" in match:
        letters, turns = match.split("-")
        print(letters, "loosen", turns)
