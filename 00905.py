class Solution:
    def sortArrayByParity(self, nums: list[int]) -> list[int]:
        n = len(nums)
        start = 0; end = n-1
        while start < end:
            if nums[start]%2 == 1:
                nums[end],nums[start] = nums[start],nums[end]
                end -= 1
            else:
                start += 1
        return nums
