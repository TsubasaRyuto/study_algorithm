# Brute Force Search in Ruby

text = 'algorithm'
target = 'hm'

def search(text, target)
  i = 0
  j = 0

  while i + j < text.size
    if target[j] == text[i + j]
      j += 1
      return i if j == target.size
    else
      i += 1
      j = 0;
    end
  end

  return nil
end

result = search(text, target)

p result
