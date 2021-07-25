# Lexicographically Least Substring

t = input()
l = int(input())

print(min(t[i:i+l] for i in range(len(t)-l+1)))