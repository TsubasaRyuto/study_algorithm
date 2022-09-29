"""
1. Input: [11, 2, 5, 9, 10, 3], 12 => Output: (2, 10) or None
2. Input: [11, 2, 5, 9, 10, 3]     => Output: (11, 9) or None ex) 11 + 9 = 2 + 5 + 10 + 3
"""

from typing import List, Tuple, Optional

def get_paire(list, num):
    for x in list:
        val = num - x
        if val in list:
            return val, x

print(get_paire([11, 2, 5, 9, 10, 3], 12))
