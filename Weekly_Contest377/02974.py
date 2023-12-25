class Solution:
    def numberGame(self, nums: list[int]) -> list[int]:
        nums.sort()
        for i in range(0,len(nums),2):
            tmp = nums[i]
            nums[i] = nums[i+1]
            nums[i+1] = tmp
        return nums