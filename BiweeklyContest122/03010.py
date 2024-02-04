from numpy import inf
class Solution:
    def minimumCost(self, nums: list[int]) -> int:
        min_val = inf; secMin = inf
        for num in nums[1:]:
            if(num < min_val):
                secMin = min_val
                min_val = num
            elif num < secMin: secMin = num
        
        return nums[0] + min_val + secMin