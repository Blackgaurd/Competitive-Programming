# BlueBook - Digits

# 65 characters
#[print(len(str(abs(int(input()))))) for i in range(int(input()))]

# 59 characters
#a=input
#for i in range(int(a())):print(len(a().strip('-')))

# 74 characters
#import re;a=input
#for i in range(int(a())):print(len(re.sub('\-','',a())))

# 63 characters
#a=input
#for i in range(int(a())):print(len(str(abs(int(a())))))

a=input
for i in range(int(a())):print(len(str(abs(int(a())))))
