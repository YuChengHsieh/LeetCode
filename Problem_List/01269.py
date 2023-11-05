# memorization
class Solution:
    def numWays(self, steps: int, arrLen: int) -> int:
        mem = {}
        MOD = 1e9+7
        threshold = min(steps//2+1,arrLen)
        def rec(pos,step):
            if pos >= threshold or pos < 0 : return 0
            if step == steps:
                return 1 if pos == 0 else 0
            if (pos,step) in mem: return mem[(pos,step)]
            
            cnt1 = rec(pos-1,step+1)%MOD
            cnt2 = rec(pos+1,step+1)%MOD
            cnt3 = rec(pos,step+1)%MOD

            mem[(pos,step)] = (cnt1+cnt2+cnt3)%MOD
            return mem[(pos,step)]
        return int(rec(0,0)%MOD)

# Bottom up dp
class Solution:
    def numWays(self, steps: int, arrLen: int) -> int:
        MOD = 1e9+7
        n = min(steps//2+1,arrLen)
        dp = [[0]* n for _ in range(steps+1)]
        dp[-1][0] = 1
        for i in range(steps-1,-1,-1):
            for j in range(n):
                dp[i][j] = dp[i+1][j]
                if j-1 >= 0:
                    dp[i][j] = (dp[i][j]+dp[i+1][j-1])%MOD
                if j+1 < n:
                    dp[i][j] = (dp[i][j]+dp[i+1][j+1])%MOD
        return int(dp[0][0])