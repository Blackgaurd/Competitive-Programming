# Phantom's Python Challenge
# remove all possible spaces and
# newlines before submitting

(s := [n := int(input())] * n), [
    s.__setitem__(slice(p + p, n, p), (~-n // p - 1) * [0])
    == print(f"{p}" + p % 2 * "*" * (s[p - 2] > -s[p + 2]))
    for p in range(2, n)
    if s[p]
]
