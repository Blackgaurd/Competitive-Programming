# Mirrored Pairs

import sys

print("Ready")
for i in sys.stdin:
    if i == "  \n":
        break
    print("Mirrored" if i[:-1] in ['pq', 'qp', 'bd', 'db'] else "Ordinary", "pair")