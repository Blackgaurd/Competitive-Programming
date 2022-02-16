# CCO '03 P5 - Longest Substring

arr = []
freq = [0] * ((1 << 16) + 1)
while a := int(input()):
    arr.append(a)

lp, rp = 0, 0
mx = 0
ans_p = 0
while rp < len(arr):
    cur = arr[rp]
    freq[cur] += 1
    while freq[cur] > 1:
        pre = arr[lp]
        freq[pre] -= 1
        lp += 1

    if rp - lp + 1 > mx:
        mx = rp - lp + 1
        ans_p = rp

    rp += 1

for i in range(ans_p - mx, ans_p):
    print(arr[i + 1])