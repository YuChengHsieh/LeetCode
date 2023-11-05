class Solution:
    def soupServings(self, n: int) -> float:
        if n > 4800: return 1
        n = (n+24)//25
        dp = [[-1 for _ in range(n+1)] for _ in range(n+1)]
        def rec(a,b):
            if a<=0 and b>0: return 1
            elif a<=0 and b<=0: return 0.5
            elif a>0 and b<=0: return 0
            elif dp[a][b] != -1: return dp[a][b]
            ans = 0
            ans += rec(a-4,b)
            ans += rec(a-3,b-1)
            ans += rec(a-2,b-2)
            ans += rec(a-1,b-3)
            dp[a][b] = 0.25*ans
            return dp[a][b]
        return rec(n,n)

