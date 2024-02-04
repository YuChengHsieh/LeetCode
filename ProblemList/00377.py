class Solution:
    def combinationSum4(self, nums: list[int], target: int) -> int:
        # coin change problem
        dp = [0 for _ in range(target+1)]
        dp[0] = 1

        for i in range(1,target+1):
            for j in nums:
                if i-j >= 0:
                    dp[i] += dp[i-j]
        
        return dp[-1]