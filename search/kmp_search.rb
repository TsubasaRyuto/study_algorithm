# KMP search in Ruby

text = 'abcabdabdacbda'
target = 'abdac'

def search(text, target)
  i = 0
  j = 0
  skip_table = [1, 1, 2, 3, 3]

  while i + j < text.size
    if target[j] == text[i + j]
      j += 1
      return i if j == target.size
    else
      i += skip_table[j]
      j = 0;
    end
  end

  return nil
end

result = search(text, target)

p result
