# CCC '12 J1 - Speed fines are not fine!

a = -int(input()) + int(input())
if a <= 0:
    print("Congratulations, you are within the speed limit!")
elif a <= 20:
    print("You are speeding and your fine is $100.")
elif a <= 30:
    print("You are speeding and your fine is $270.")
else:
    print("You are speeding and your fine is $500.")
