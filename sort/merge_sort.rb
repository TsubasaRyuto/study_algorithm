# Merge sort in Ruby

array = [90, 5, 2, 80, 7, 10, 1, 70, 3, 100, 8, 4, 120, 9, 6, 150]

puts "Before"
p array
puts ""

def merge_sort(array, left, right)
  return array if (right - left == 1)

  mid = left + (right - left) / 2

  # 左半分
  merge_sort(array, left, mid)

  # 右半分
  merge_sort(array, mid, right)

  buf = [];

  i = left
  while (i < mid)
    buf.push array[i]
    i += 1
  end

  i = right - 1
  while (i >= mid)
    buf.push array[i]
    i -= 1
  end

  index_left = 0;
  index_right = buf.size - 1

  i = left
  while (i < right)
    if (buf[index_left] <= buf[index_right])
      array[i] = buf[index_left];
      index_left += 1
    else
      array[i] = buf[index_right];
      index_right -= 1
    end

    i += 1
  end

  return array
end

merge_sort(array, 0, array.size)

puts "After"
p array

