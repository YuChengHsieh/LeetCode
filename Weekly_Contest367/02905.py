class Solution:
    def findIndices(self, nums: list[int], indexDifference: int, valueDifference: int) -> list[int]:
        n = len(nums)
        min_idx = max_idx = 0
        for i in range(indexDifference,n):
            if nums[i-indexDifference] < nums[min_idx]: min_idx = i-indexDifference
            if nums[i-indexDifference] > nums[max_idx]: max_idx = i-indexDifference
            if nums[i]-nums[min_idx] >= valueDifference: return [min_idx,i]
            if nums[max_idx]-nums[i] >= valueDifference: return [max_idx,i]
        return [-1,-1]