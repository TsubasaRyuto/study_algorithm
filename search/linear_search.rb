# Linear search in Ruby

def find_number(array, y)
  result_index = nil
  array.each_with_index do |i, a|
    if a == y
      result_index = i
      break
    end
  end

  return p "#{y}はarrayの#{result_index + 1}番目にあります" if !result_index.nil?
  p "#{y}はarrayに存在しません"
end

find_number([*1..1000].shuffle, 115)

