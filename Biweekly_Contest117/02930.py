class Solution:
    def stringCount(self, n: int) -> int:
        dp = [[[[-1 for _ in range(2)] for _ in range(3)] for _ in range(2)] for _ in range(n+1)]
        mod = 10**9 + 7
        def dfs(n,l,e,t):
            if n == 0:
                return 1 if l == 0 and e == 0 and t == 0 else 0
            if dp[n][l][e][t] != -1 : return dp[n][l][e][t]
            ans = dfs(n-1,l,e,t)*23%mod
            ans = (ans + dfs(n-1,max(0,l-1),e,t))%mod
            ans = (ans + dfs(n-1,l,max(0,e-1),t))%mod
            ans = (ans + dfs(n-1,l,e,max(0,t-1)))%mod
            dp[n][l][e][t] = ans
            return ans
        return dfs(n,1,2,1)