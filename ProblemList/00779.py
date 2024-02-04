class Solution:
    def kthGrammar(self, n: int, k: int) -> int:
        # bit operation
        cnt = 0
        k -= 1
        while k != 0:
            k &= (k-1)
            cnt += 1
        return 0 if cnt%2 == 0 else 1
         
