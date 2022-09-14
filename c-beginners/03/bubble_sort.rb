# bubble sort in Ruby
#
array = [5, 2, 7, 10, 1, 3, 8, 4, 9, 6]

puts "before:"
p array
puts ""

current_index = 0
search_index = array.size

while (array.size > current_index)
  inner_index = 0
  search_index -= 1

  while (inner_index < search_index)
    if array[inner_index] > array[inner_index + 1]
      tmp = array[inner_index]
      array[inner_index] = array[inner_index + 1]
      array[inner_index + 1] = tmp
    end

    inner_index += 1
  end

  current_index += 1
end

puts "after:"
p array
