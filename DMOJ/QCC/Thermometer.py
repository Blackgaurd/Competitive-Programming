# QCC P0 - Thermometer

import sys
input = sys.stdin.readline

for i in range(int(input())):
    t = float(input())
    if t < 34:
        print("Too cold, please try again.")
    elif t <= 35.5:
        print("Take a hot bath.")
    elif t <= 38:
        print("Rest if feeling unwell.")
    elif t <= 39:
        print("Take some medicine.")
    elif t <= 41:
        print("Take a cold bath and some medicine.")
    elif t <= 46.1:
        print("Go to the hospital.")
    elif t <= 50:
        print("Congrats, you have a new world record!")
    else:
        print("Too hot, please try again.")