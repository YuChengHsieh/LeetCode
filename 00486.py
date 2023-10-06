# game theory
class Solution:
    def PredictTheWinner(self, nums: list[int]) -> bool:
        dp = [[-1 for _ in range(len(nums))] for _ in range(len(nums))]
        def rec(l,r):
            if dp[l][r] != -1:
                return dp[l][r]
            if l == r:
                return nums[l]
            
            left = nums[l] - rec(l+1,r)
            right = nums[r] - rec(l,r-1)
            dp[l][r] = max(left,right)
            return dp[l][r]
            
        return rec(0,len(nums)-1) >= 0