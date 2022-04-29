# MALD Contest 1 P2 - Scratch Cat and Examinations

for i in range(int(input())):
    print("sus" if (score := __import__("math").ceil(int.__truediv__(*map(int, input().split())) * 100)) > 100 else "average" if score == 100 else "below average" if score >= 98 else "can't eat dinner" if score >= 95 else "don't come home" if score >= 90 else "find a new home")
