# DMOPC '19 Contest 6 P0 - Trivial Math

a = sorted(map(int, input().split()))
print("yes" if a[0] + a[1] > a[2] else "no")
