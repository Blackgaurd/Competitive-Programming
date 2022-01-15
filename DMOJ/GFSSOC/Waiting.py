# Waiting

from datetime import datetime

a = datetime.strptime(input(), "%H:%M:%S")
b = datetime.strptime(input(), "%H:%M:%S")
print(int((b - a).total_seconds()))
