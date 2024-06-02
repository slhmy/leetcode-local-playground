# Source: https://leetcode.cn/problems/group-anagrams/
# Tags: hash-table, string

import os
import sys
from typing import List

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = {}
        for s in strs:
            key = "".join(sorted(s))
            d[key] = d.get(key, []) + [s]
        return list(d.values())

sys.path.append(os.path.join(os.path.dirname(__file__), '../'))
from helper.json_input import read_vector_from_json_str
from helper.json_output import print_vector_as_json

print("group-anagrams")
strs = read_vector_from_json_str()
solution = Solution()
print_vector_as_json(solution.groupAnagrams(strs))