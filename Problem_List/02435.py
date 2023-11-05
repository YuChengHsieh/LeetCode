class Solution:
    def numberOfPaths(self, grid: list[list[int]], k: int) -> int:
        MOD = 1e9+7
        dp = [[[0 for _ in range(k)] for _ in range(len(grid[0])+1)] for _ in range(len(grid)+1)]
        dp[1][1][grid[0][0]%k] = 1
        for i in range(1,len(grid)+1):
            for j in range(1,len(grid[0])+1):
                for l in range(k):
                    val = (l+grid[i-1][j-1])%k
                    dp[i][j][val] += int((dp[i-1][j][l]+dp[i][j-1][l])%MOD)
        return dp[-1][-1][0]