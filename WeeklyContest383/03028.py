class Solution:
    def returnToBoundaryCount(self, nums: list[int]) -> int:
        sum_ = 0; cnt = 0
        for num in nums:
            sum_ += num
            if sum_ == 0: cnt += 1
        return cnt