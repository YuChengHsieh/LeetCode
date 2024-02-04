from math import log
class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        # back tracking
        def rec(n):
            if n == 0: return 0
            k = int(log(n,2))
            return 2**(k+1)-1 - rec(n^(1<<k))
        return rec(n)