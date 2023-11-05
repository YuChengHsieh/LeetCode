class Solution:
    def calculateMinimumHP(self, dungeon: list[list[int]]) -> int:
        # bottom-top method
        m,n = len(dungeon),len(dungeon[0])
        dp = [[float('inf') for _ in range(n+1)] for _ in range(m+1)]
        dp[m][n-1] = 1; dp[m-1][n] = 1

        for i in range(m-1,-1,-1):
            for j in range(n-1,-1,-1):
                dp[i][j] = max(min(dp[i+1][j],dp[i][j+1])-dungeon[i][j],1)
        
        return dp[0][0]