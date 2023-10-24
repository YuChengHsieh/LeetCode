class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        start = 0; end = 30

        while start <= end:
            mid = start+(end-start)//2
            if 3**mid == n: return True
            elif 3**mid < n: start = mid+1
            else: end = mid -1
        return False

# use log
class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        import math
        if n <= 0: return False
        x = log(n,3)
        e = round(x,1)
        return True if 3**e == n else False