# A. Lucky Division

nums = [4, 7, 44, 47, 74, 77, 444, 447, 474, 744, 774, 747, 477, 777]
n = int(input())
print("YES" if any(n % i == 0 for i in nums) else "NO")
