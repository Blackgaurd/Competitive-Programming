# BlueBook - Equation

a = float(input())
b = float(input())

if a == 0:
    if b == 0:
        print("indeterminate")
    else:
        print("undefined")
else:
    print(f"{-b / a:.2f}")
