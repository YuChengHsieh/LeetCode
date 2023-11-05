class Solution:
    def rob(self, nums: list[int]) -> int:
        if len(nums) <= 3: return max(nums)
        max_ = 0
        dp = [0 for _ in range(len(nums)-1)]
        dp[0] = nums[0]
        dp[1] = nums[1]
        for i in range(2,len(nums)-1):
            dp[i] = max(dp[i-2],dp[i-3]) + nums[i]
        max_ = max(dp[-1],dp[-2])

        dp = [0 for _ in range(len(nums)-1)]
        dp[0] = nums[1]
        dp[1] = nums[2]
        for i in range(2,len(nums)-1):
            dp[i] = max(dp[i-2],dp[i-3]) + nums[i+1]
        max_ = max(dp[-1],dp[-2],max_)
        return max_