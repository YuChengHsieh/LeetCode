# Use sum
class Solution:
    def missingNumber(self, nums: list[int]) -> int:
        # sum
        n = len(nums)
        return sum([i for i in range(1,n+1)]) - sum([num for num in nums])

# Use sum o(n) time and o(1) space
class Solution:
    def missingNumber(self, nums: list[int]) -> int:
        # sum
        n = len(nums)
        sum1 = n*(n+1)//2; sum2 = 0
        for num in nums:
            sum2 += num
        return sum1-sum2
