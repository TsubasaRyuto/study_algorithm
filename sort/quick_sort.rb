# Quick Sort in Ruby

def quick_sort(array)
  return array if (array.size <= 1)

  pivot = array[rand(array.size)]

  smaller_array = []
  bigger_array = []

  array.each do |num|
    if num <= pivot
      smaller_array.push num
    else
      bigger_array.push num
    end
  end

  left = quick_sort(smaller_array)  # 左半分
  right = quick_sort(bigger_array) # 右半分

  left + right
end

array = [3, 1, 4, 5, 2, 6]
quick_sort(array)
