import sys
import re

input = sys.stdin.readline

count = 0
prev = ""


def match(strg, search=re.compile(r'[^a-z0-9]').search):
    return not bool(search(strg))


def check(str):
    byr = False
    iyr = False
    eyr = False
    hgt = False
    hcl = False
    ecl = False
    pid = False
    str = str.split(" ")
    str.sort()
    for val in str:
        val = val.split(":")
        if val[0] == 'byr' and 1920 <= int(val[1]) <= 2002: byr = True
        if val[0] == 'iyr' and 2010 <= int(val[1]) <= 2020: iyr = True
        if val[0] == 'eyr' and 2020 <= int(val[1]) <= 2030: eyr = True
        if val[0] == 'hgt':
            if val[1][-1] == 'n' and 59 <= int(val[1][:-2]) <= 76:
                hgt = True
            elif val[1][-1] == 'm' and 150 <= int(val[1][:-2]) <= 193:
                hgt = True
        if val[0] == 'hcl' and val[1][0] == '#' and len(val[1][1:]) == 6 and match(val[1][1:]): hcl = True
        if val[0] == 'ecl' and val[1] in ['amb', 'blu', 'brn', 'gry', 'grn', 'hzl', 'oth']: ecl = True
        if val[0] == 'pid' and len(val[1]) == 9: pid = True
    return (byr and iyr and eyr and hgt and hcl and ecl and pid)


while True:
    t = input()
    if t == '0\n': break
    if t == "\n":
        if check(prev): count += 1
        prev = ""
    prev += " " + t[:-1]
    # print(prev)

print(count)
