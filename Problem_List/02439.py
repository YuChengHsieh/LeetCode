class Solution:
    def minimizeArrayValue(self, nums: list[int]) -> int:
        max_num = 0
        sum_ = 0
        for i in range(len(nums)):
            sum_ += nums[i]
            if (sum_-1)//(i+1)+1 > max_num:
                max_num = (sum_-1)//(i+1)+1
        return max_num