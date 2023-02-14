# Yet Another Contest 5 P1 - Number Pyramid

n, k, x = map(int, input().split())

max_sum = pow(2, n-1, k) * (k - 1) % k
print((max_sum - x) % k)
