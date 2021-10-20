# DMOPC '19 Contest 4 P0 - Yikes

cnt = sum(i[0] != i[1] for i in zip(input(), input()))
print(f"LARRY IS {'SAVED' if cnt == 1 else 'DEAD'}!")