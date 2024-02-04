class Solution:
    def singleNumber(self, nums: list[int]) -> int:
        # bit operation
        ans = 0
        for num in nums:
            ans ^= num
        return ans