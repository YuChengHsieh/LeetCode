from numpy import inf
class Solution:
    def minDifficulty(self, jobDifficulty: list[int], d: int) -> int:
        if len(jobDifficulty) < d: return -1
        n = len(jobDifficulty)+1
        dp = [[inf]*d for _ in range(n)]
        last_max = 0
        dp[0][0] = 0
        for i in range(1,n):
            last_max = max(last_max,jobDifficulty[i-1])
            dp[i][0] = last_max
        for i in range(1,d):
            for j in range(i,n):
                last_max = jobDifficulty[j-1]
                dp[j][i] = last_max + dp[j-1][i-1]
                for k in range(j-1,i,-1):
                    if jobDifficulty[k-1] > last_max: 
                        last_max = jobDifficulty[k-1]
                    dp[j][i] = min(dp[j][i],dp[k-1][i-1]+last_max)
        return dp[-1][-1]
