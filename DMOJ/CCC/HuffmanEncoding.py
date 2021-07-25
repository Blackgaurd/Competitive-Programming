# CCC '10 S2 - Huffman Encoding

k = int(input())
mp = {}
for i in range(k):
    a, b = input().split()
    mp[b] = a

code = input()
ans = ""
while code:
    for k, v in mp.items():
        if code.startswith(k):
            ans += v
            code = code[len(k):]

print(ans)