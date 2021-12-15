# Mock CCC '22 S3 - IU

n = int(input())
t = input() + "."

i_cnt, u_cnt = 0, 0
for i in range(len(t) - 1):
    if t[i] == "I" and t[i + 1] != "U":
        i_cnt += 1
    elif t[i] == "U" and t[i - 1] != "I":
        u_cnt += 1

print(i_cnt if i_cnt == u_cnt else -1)
