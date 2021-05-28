import sys
sys.setrecursionlimit(1000)
mod = 1000000009
nums = {}


def fib(n):
    if n in nums: return nums[n]
    nums[n] = (fib((n-1)//2)*fib((n-2)//2)+fib(n//2)*fib((n+1)//2))%mod
    return nums[n]



a, b, c = map(int, input().split())
nums[0] = a
nums[1] = b
nums[2] = a+b
print(fib(c))
