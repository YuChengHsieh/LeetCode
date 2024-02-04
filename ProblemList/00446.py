from collections import defaultdict
class Solution:
    def numberOfArithmeticSlices(self, nums: list[int]) -> int:
        n = len(nums)
        dp = [defaultdict(int) for _ in range(n)]
        ans = 0
        for i in range(n):
            for j in range(i):
                if nums[i] - nums[j] in dp[j]:
                    ans += dp[j][nums[i] - nums[j]] 
                    dp[i][nums[i] - nums[j]] += dp[j][nums[i] - nums[j]]
                dp[i][nums[i]-nums[j]] += 1
        return ans


        