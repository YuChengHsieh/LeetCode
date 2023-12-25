from numpy import inf
class Solution:
    def maxProductDifference(self, nums: list[int]) -> int:
        max_num = second_max = 0
        min_num = second_min = inf

        for num in nums:
            if num > max_num:
                second_max = max_num
                max_num = num
            elif num > second_max: second_max = num

            if num < min_num:
                second_min = min_num
                min_num = num
            elif num < second_min: second_min = num

        return max_num*second_max - min_num*second_min