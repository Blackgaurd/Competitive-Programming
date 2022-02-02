# Mock CCC '22 Contest 1 J3 - String Crossing Maximization

n, m = map(int, input().split())
s = input()
t = input()

freqs = {}
for char in s:
    if char not in freqs:
        freqs[char] = 0
    freqs[char] += 1

mx, mn = max(freqs.values()), int(1e9)

ans = 0
for char in t:
    cnt = freqs.get(char, 0)
    ans += cnt
    mn = min(mn, cnt)

ans += mx - mn
print(ans)