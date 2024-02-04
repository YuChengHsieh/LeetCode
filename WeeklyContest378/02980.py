class Solution:
    def hasTrailingZeros(self, nums: list[int]) -> bool:
        cnt = 0
        for num in nums:
            if num & 1 == 0: cnt += 1
        return True if cnt >= 2 else False