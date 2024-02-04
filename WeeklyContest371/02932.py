class Solution:
    def maximumStrongPairXor(self, nums: list[int]) -> int:
        n = len(nums)
        ans = 0
        for i in range(n):
            for j in range(i,n):
                if abs(nums[i]-nums[j]) <= min(nums[i],nums[j]):
                    ans = max(ans,nums[i]^nums[j])
        return ans