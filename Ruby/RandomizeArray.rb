#RandomizeArray.rb

j_array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]

def randomize(inp_arr)
    i = 0
    while i < (inp_arr.size - 1)
        n = rand(inp_arr.size)
        val = inp_arr[n]
        inp_arr[n] = inp_arr[i]
        inp_arr[i] = val
        i += 1
    end
end

print j_array
puts ""
puts "Randomize to"
randomize(j_array)
print j_array
puts ""