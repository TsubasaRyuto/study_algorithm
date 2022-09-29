# selection sort in Ruby

array = [5, 2, 7, 10, 1, 3, 8, 4, 9, 6]
puts "before:"
p array
puts ""

current_index = 0
min_num_index = 0

while (array.size > current_index)
  min_num = array[current_index]
  min_num_index = current_index
  index = current_index + 1

  while (array.size != index)
    if min_num > array[index]
      min_num = array[index]
      min_num_index = index
    end

    index += 1;
  end

  array[min_num_index] = array[current_index]
  array[current_index] = min_num

  current_index += 1
end

puts "after:"
p array
