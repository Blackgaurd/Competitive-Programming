# UTS Open '21 P2 - Prime Array

k = int(input())

def fn(n):
    return n * (n - 1) // 2

def gen_array(length):
    ret = []
    flip = True
    for i in range(length):
        ret.append(2 if flip else 3)
        flip = not flip
    return ret

arr_len = -1
for i in range(2, 102):
    if fn(i) > k:
        arr_len = i
        break

arr_len -= 1
arr = gen_array(arr_len)
cnt = fn(arr_len)

for i in range(k - cnt):
    arr[i] = 1

print(len(arr))
print(*arr)
