# Polygon Area

n = int(input())
points = [tuple(map(int, input().split())) for i in range(n)]
area = sum(
    (points[i - 1][0] + points[i][0]) * (points[i - 1][1] - points[i][1])
    for i in range(len(points))
)
print(abs(area))
