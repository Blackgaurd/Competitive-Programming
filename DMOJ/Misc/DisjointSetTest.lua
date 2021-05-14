-- Disjoint Set Test
-- written in lua because why not
-- basically a translation of my c++ code

local stdin, input, print = io.stdin, io.stdin.read, io.write

local p = {}
function Flead(x)
    if p[x] ~= x then
        p[x] = Flead(p[x])
    end
    return p[x]
end

local ans = {}
local n, m = input(stdin, "*n", "*n")
for i=1, n do
    p[i] = i
end
for i=1, m do
    local a, b = input(stdin, "*n", "*n")
    if Flead(a) ~= Flead(b) then
        table.insert(ans, i)
        p[Flead(a)] = Flead(b)
    end
end
if #ans == n-1 then
    for i=1, #ans do
        print(ans[i], "\n")
    end
else
    print("Disconnected Graph\n")
end