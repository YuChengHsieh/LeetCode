class Solution:
    def countOrders(self, n: int) -> int:
        cnt = 1
        for i in range(n*2,0,-1):
            cnt *= i
            if i%2 == 0: cnt //= 2
        return cnt%(10**9 + 7)

class Solution:
    def countOrders(self, n: int) -> int:
        cnt = 1
        for i in range(2,n*2+1):
            cnt *= i
            if i%2 == 0: cnt //= 2
        return cnt%(10**9 + 7)