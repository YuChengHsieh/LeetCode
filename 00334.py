from numpy import inf
class Solution:
    def increasingTriplet(self, nums: list[int]) -> bool:
        a = b = inf
        for num in nums:
            if num <= a: a = num
            elif num <= b: b = num
            else: return True
        return False