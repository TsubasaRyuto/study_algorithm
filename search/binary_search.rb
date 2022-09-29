# binary search in Ruby


def find_number_index(array, y)
  left = 0
  right = array.size - 1

  while(right >= left)
    mid = left + (right - left) / 2

    return mid if array[mid] == y
    left = mid + 1 if array[mid] < y
    right = mid - 1 if array[mid] > y
  end

  return -1

end

array = [8, 9, 15, 18, 19, 24, 29, 31, 33, 36, 43, 50, 99, 101]
y = 101

result = find_number_index(array, y)

p "#{y}はarrayの#{result + 1}番目にあります" if result > 0
p "#{y}はarrayに存在しません" if result < 0

