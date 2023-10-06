# DP o(n) 
from numpy import inf
class Solution:
    def minSideJumps(self, obstacles: list[int]) -> int:
        dp = [[inf for _ in range(3)] for _ in range(len(obstacles))]
        dp[0][1] = 0; dp[0][0] = dp[0][2] = 1
        for i in range(len(obstacles)-1):
            for j in range(3):
                if obstacles[i+1] == j+1:
                    dp[i+1][j] = inf
                else:
                    cmp = [dp[i][k]+1 for k in range(3) if k != j and obstacles[i+1] != k+1]
                    dp[i+1][j] = min(*cmp,dp[i][j])
        return min(dp[-1])

# Faster
class Solution:
    def minSideJumps(self, obstacles: list[int]) -> int:
        dp = [1,0,1]
        for obstacle in obstacles:
            if obstacle:
                dp[obstacle-1] = inf
            for i in range(3):
                if obstacle != i+1:
                    dp[i] = min(dp[i],dp[(i+1)%3]+1,dp[(i+2)%3]+1)
        return min(dp)