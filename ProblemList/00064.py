class Solution:
    def minPathSum(self, grid: list[list[int]]) -> int:
        row_len = len(grid)
        col_len = len(grid[0])
        dp = [] # dp[i,j] record minimum sum from [0,0] to dp[i,j]
        for _ in range(row_len):
            dp.append([0 for _ in range(col_len)])
        for i in range(row_len):
            for j in range(col_len):
                if i == 0 and j == 0:
                    dp[i][j] = grid[i][j]
                elif i == 0:
                    dp[i][j] = dp[i][j-1] + grid[i][j]
                elif j == 0:
                    dp[i][j] = dp[i-1][j] + grid[i][j]
                else:
                    dp[i][j] = min(dp[i-1][j],dp[i][j-1])+grid[i][j]

        return dp[row_len-1][col_len-1]

if __name__ == '__main__':
    a = Solution()
    print(a.minPathSum([[1,3,1],[1,5,1],[4,2,1]]))
                
        
        