# WC '15 Contest 4 J2 - Mission Briefing

t = input()
ans = sum(f"00{i}" in t for i in range(1, 10))
print(ans)
