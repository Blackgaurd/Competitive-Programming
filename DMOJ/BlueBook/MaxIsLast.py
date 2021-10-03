# BlueBook - Max is Last

arr = [float(input()) for i in range(int(input()))]
mx = max(arr)
[print("%.2f" % i) for i in arr if i != mx]
print("%.2f" % mx)