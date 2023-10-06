# Top down DP, o(n^2)
class Solution:
    def maximumJumps(self, nums: list[int], target: int) -> int:
        dp = [-1 for _ in range(len(nums))]
        dp[0] = 0
        for i in range(len(nums)):
            for j in range(i):
                if -target <= nums[i]-nums[j] <= target and dp[j] != -1:
                    dp[i] = max(dp[i],dp[j]+1)
        return -1 if dp[-1] == 0 else dp[-1]