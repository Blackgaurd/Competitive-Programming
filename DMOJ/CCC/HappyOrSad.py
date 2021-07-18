# CCC '15 J2 - Happy or Sad

line = input()

h = line.count(":-)")
s = line.count(":-(")
if h > s:
    print("happy")
elif h < s:
    print("sad")
elif h + s == 0:
    print("none")
else:
    print("unsure")
