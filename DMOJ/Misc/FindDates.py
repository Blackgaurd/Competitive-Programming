# Find Dates

import re
import sys
import datetime
for year in re.findall("[0-9]{4}-[0-9]{2}-[0-9]{2}", sys.stdin.read()):
    try:
        datetime.datetime(*map(int, year.split('-')))
    except:
        continue
    else:
        print(year)