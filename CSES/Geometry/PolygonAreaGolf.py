p,k=int,input
l=range(p(k()))
a=[list(map(p,k().split()))for i in l]
print(abs(sum((a[i-1][0]+a[i][0])*(a[i-1][1]-a[i][1])for i in l)))