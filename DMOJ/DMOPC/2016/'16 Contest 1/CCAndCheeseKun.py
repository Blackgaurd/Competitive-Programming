# DMOPC '16 Contest 1 P0 - C.C. and Cheese-kun

w = int(input())
c = int(input())

if w == 3 and c >= 95:
    lvl = "absolutely"
elif w == 1 and c <= 50:
    lvl = "fairly"
else:
    lvl = "very"

print("C.C. is %s satisfied with her pizza." % (lvl))