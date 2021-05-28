import sys
input = sys.stdin.readline

n = int(input())
sol = n
arr = list(map(int, input().split()))
psa = [0]

for i in range(1, n+1):
    psa[i] = psa[i-1]+arr[i-2]

for i in range(1, n-1):
    for j in range(i+1, n):
        s = psa[j]-psa[i-1]
        d = j-i+1
        avg = s/d
        for k in range(i, j+1):
            if arr[i:j].count(avg)>0:
                sol+=1

print(sol)