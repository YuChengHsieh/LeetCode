class Solution:
    def validPartition(self, nums: list[int]) -> bool:
        dp = [False for _ in range(len(nums)+1)]
        dp[0]= True
        dp[2] = dp[0] and nums[0]==nums[1]

        for i in range(3,len(nums)+1):
            dp[i] = (dp[i-3] and nums[i-1] == nums[i-2] == nums[i-3]) or\
                    (dp[i-3] and nums[i-1] == nums[i-2]+1 == nums[i-3]+2) or\
                    (dp[i-2] and nums[i-1] == nums[i-2])
        return dp[-1]

# recursive + memorization
class Solution:
    def validPartition(self, nums: list[int]) -> bool:
        dp = [-1 for _ in range(len(nums)+1)]
        dp[0]= 1 #True
        dp[1] = 0 #False
        dp[2] = dp[0] and nums[0]==nums[1]

        def rec(i):
            if i<0: return 1
            if dp[i] != -1: return dp[i]
            dp[i] = (rec(i-3) and nums[i-1] == nums[i-2] == nums[i-3]) or\
                    (rec(i-3) and nums[i-1] == nums[i-2]+1 == nums[i-3]+2) or\
                    (rec(i-2) and nums[i-1] == nums[i-2])
            return dp[i]
        return rec(len(nums))