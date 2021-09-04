# Remove Cancer

import re

[print(re.sub("[^01]", "0", input())) for i in range(int(input()))]