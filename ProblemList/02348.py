class Solution:
    def zeroFilledSubarray(self, nums: list[int]) -> int:
        zero_cnt = 0
        continuous = 1
        for num in nums:
            if num == 0:
                zero_cnt += continuous
                continuous += 1
            else:
                continuous = 1
        return zero_cnt