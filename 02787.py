class Solution:
    def numberOfWays(self, n: int, x: int) -> int:
        MOD = 1e9+7
        dp = [0 for _ in range(n+1)]
        dp[0] = 1
        cur = 1
        while cur**x <= n:
            for i in range(n,cur**x-1,-1):
                dp[i] += dp[i-cur**x]
            cur += 1
        # print(dp)
        return int(dp[-1]%MOD)