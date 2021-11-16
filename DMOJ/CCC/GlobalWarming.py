# CCC '10 J4 - Global Warming

while True:
    nums = input()
    if nums == "0":
        break
    nums = list(map(int, nums.split()))
    n = nums.pop(0)
    op = []
    if n == 1:
        print(0)
        continue
    for i in range(1, n):
        op.append(nums[i] - nums[i - 1])
    cycle = 1
    for c in range(1, len(op)):
        flag = True
        for i in range(len(op)):
            if op[i] != op[i % cycle]:
                flag = False
        if flag:
            break
        cycle += 1
    print(cycle)
