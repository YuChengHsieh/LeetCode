class Solution:
    def numOfArrays(self, n: int, m: int, k: int) -> int:
        dp = [[[0 for _ in range(m)] for _ in range(k)] for _ in range(n)]
        mod = 1e9+7
        for i in range(m):
            dp[0][0][i] = 1

        for i in range(1,n):
            for j in range(min(k,i+1)):
                for l in range(m):
                    # will not change the maximum => search cost unchange
                    dp[i][j][l] = (dp[i-1][j][l]*(l+1))%mod
                    if j != 0:
                        # will change the current maximum by adding l => search cost + 1
                        sum_ = 0
                        for o in range(l):
                            sum_ += dp[i-1][j-1][o]
                            sum_ %= mod
                        dp[i][j][l] = (dp[i][j][l]+sum_)%mod
        ans = 0
        for i in range(m):
            ans += dp[n-1][k-1][i]
            ans %= mod
        return int(ans%mod)
                    