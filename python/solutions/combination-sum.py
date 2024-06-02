# Source: https://leetcode.cn/problems/combination-sum/
# Tags: array, depth-first-search

import os
import sys
from typing import List


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:

        def dfs(idx, target, combination):
            if target == 0:
                result.append(combination)
                return
            if idx == len(candidates):
                return

            if candidates[idx] <= target:
                dfs(idx, target - candidates[idx], combination + [candidates[idx]])
            dfs(idx + 1, target, combination)

        result = []
        candidates.sort()
        dfs(0, target, [])
        return result


sys.path.append(os.path.join(os.path.dirname(__file__), "../"))
from helper.json_input import read_vector_from_json_str
from helper.json_output import print_vector_as_json

print("combination-sum")
candidates = read_vector_from_json_str()
target = int(input())
solution = Solution()
print_vector_as_json(solution.combinationSum(candidates, target))
