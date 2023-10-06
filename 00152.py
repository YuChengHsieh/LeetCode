class Solution:
    def maxProduct(self, nums: list[int]) -> int:
        cur = 1
        max_left, max_right = -100,-100
        for i in nums:
            cur *= i
            max_left = max(cur,max_left)
            if cur == 0: cur=1
        cur = 1
        for i in nums[::-1]:
            cur *= i
            max_right = max(cur,max_right)
            if cur == 0: cur=1
        
        return max(max_left,max_right)