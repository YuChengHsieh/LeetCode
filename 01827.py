class Solution:
    def minOperations(self, nums: list[int]) -> int:
        cnt = 0
        for i in range(1,len(nums)):
            if nums[i] <= nums[i-1]:
                cnt += nums[i-1] - nums[i]+1
                nums[i] = nums[i-1]+1
        return cnt