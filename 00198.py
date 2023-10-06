class Solution:
    def rob(self, nums: list[int]) -> int:
        dp = [0 for _ in range(len(nums))]
        if len(nums) == 1: return nums[0]
        dp[0] = nums[0]
        dp[1] = nums[1]
        for i in range(2,len(nums)):
            dp[i] = max(dp[:i-1]) + nums[i]
        return max(dp)

class Solution:
    def rob(self, nums: list[int]) -> int:
        dp = [0 for _ in range(len(nums))]
        if len(nums) == 1: return nums[0]
        dp[0] = nums[0]
        dp[1] = nums[1]
        for i in range(2,len(nums)):
            dp[i] = max(dp[i-2],dp[i-3]) + nums[i]
        return max(dp[-1],dp[-2])