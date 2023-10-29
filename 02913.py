class Solution:
    def sumCounts(self, nums: list[int]) -> int:
        n = len(nums)
        sum_ = 0
        for i in range(n):
            distinct = set()
            for j in range(i,-1,-1):
                distinct.add(nums[j])
                sum_ += len(distinct)**2
        return sum_