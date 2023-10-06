class Solution:
    def isMonotonic(self, nums: list[int]) -> bool:
        tmp_val = 0
        for i in range(1,len(nums)):
            if nums[i]-nums[i-1] > 0:
                if tmp_val < 0: return False
                tmp_val = nums[i]-nums[i-1]
            elif nums[i]-nums[i-1] < 0:
                if tmp_val > 0: return False
                tmp_val = nums[i]-nums[i-1]
        return True
