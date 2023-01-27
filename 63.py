class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: list[list[int]]) -> int:
        DP = []
        row_len = len(obstacleGrid)
        col_len = len(obstacleGrid[0])
        for _ in range(row_len):
            DP.append([0 for _ in range(col_len)])

        for i in range(row_len):
            for j in range(col_len):
                if obstacleGrid[i][j] == 1: #if encounter obstacles
                    DP[i][j] = 0
                elif i == 0 and j == 0:
                    DP[i][j] = 1
                elif i == 0:
                    DP[i][j] = DP[i][j-1]
                elif j == 0:
                    DP[i][j] = DP[i-1][j]
                else:
                    DP[i][j] = DP[i-1][j] + DP[i][j-1]
        return DP[row_len-1][col_len-1]

if __name__ == '__main__':
    a = Solution()
    print(a.uniquePathsWithObstacles([[0,0,0],[0,1,0],[0,0,0]]))
    print(a.uniquePathsWithObstacles([[0,1],[0,0]]))
    print(a.uniquePathsWithObstacles([[1]]))
                