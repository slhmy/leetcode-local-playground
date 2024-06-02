# Source: https://leetcode.cn/problems/partition-equal-subset-sum/
# Tags: dynamic-programming

import os
import sys
from typing import List

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total = sum(nums)
        if total % 2 != 0:
            return False

        target = total // 2
        dp = [False] * (target + 1)
        dp[0] = True

        for num in nums:
            for i in range(target, num - 1, -1):
                dp[i] = dp[i] or dp[i - num]

        return dp[target]

sys.path.append(os.path.join(os.path.dirname(__file__), '../'))
from helper.json_input import read_vector_from_json_str

print("partition-equal-subset-sum")
nums = read_vector_from_json_str()
solution = Solution()
print(solution.canPartition(nums))