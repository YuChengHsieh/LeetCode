class Solution:
    def lengthOfLongestSubsequence(self, nums: list[int], target: int) -> int:
        dp = [-1 for _ in range(target+1)]
        dp[0] = 0
        for num in nums:
            for i in range(target,0,-1):
                if i >= num and dp[i-num] != -1: dp[i] = max(dp[i], dp[i-num]+1)
        return dp[-1]