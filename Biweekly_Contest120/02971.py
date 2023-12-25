class Solution:
    def largestPerimeter(self, nums: list[int]) -> int:
        nums.sort()
        ans = sum(nums)
        
        for i in range(len(nums)-1,-1,-1):
            if ans - nums[i] > nums[i]: break
            ans -= nums[i]
        
        return ans if i >= 2 else -1