# COCI '08 Contest 4 #1 Mjehuric

nums = input().split()

while nums != ["1", "2", "3", "4", "5"]:
    for swap in range(4):
        if nums[swap] > nums[swap + 1]:
            nums[swap], nums[swap + 1] = nums[swap + 1], nums[swap]
            print(*nums, sep=" ")
