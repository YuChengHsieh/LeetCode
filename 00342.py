class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        start = 0; end = 16

        while start <= end:
            mid = start+(end-start)//2
            if 4**mid == n: return True
            elif 4**mid < n: start = mid+1
            else: end = mid -1
        return False

# bit manipulation
class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        return n > 0 and n & (n-1) == 0 and n & 0x55555555 != 0