import sys

# Delete the first element becouse it is the file path 
sys.argv.pop(0)

list = []

for arg in sys.argv:
    list.append(int(arg))

new_list = sorted(list, reverse=True)

for list_index in range(len(new_list)):
    if list_index > 2: break
    print(new_list[list_index])
