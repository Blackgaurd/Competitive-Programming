-- CPC '19 Contest 1 P1 - Distance

local stdin, input, print = io.stdin, io.stdin.read, io.write

local lo = 1
local hi = input(stdin, "*n")

while lo <= hi do
    print(lo, " ")
    lo = lo + 1
    if hi+1 == lo then
        break
    end
    print(hi, " ")
    hi = hi - 1
end