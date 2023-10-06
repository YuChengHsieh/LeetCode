class Solution:
    def countQuadruplets(self, nums: list[int]) -> int:
        ans = 0
        for i in range(2,len(nums)):
            for j in range(1,i):
                for k in range(j):
                    ans += nums[i+1:].count(nums[i]+nums[j]+nums[k])
        return ans