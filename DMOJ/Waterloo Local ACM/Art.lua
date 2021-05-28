local stdin, input, output = io.stdin, io.stdin.read, io.write

local nums = {}
for i=1, 5 do
    nums[i] = input(stdin, "*n")
end

table.sort(nums)

local ans = 0
for i=1, 3 do
    for j=i+1, 4 do
        for k=j+1, 5 do
            if nums[i] + nums[j] > nums[k] then
                ans = ans + 1
            end
        end
    end
end

output(ans)