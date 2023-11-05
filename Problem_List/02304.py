# backtracking+memorization
class Solution:
    def minPathCost(self, grid: list[list[int]], moveCost: list[list[int]]) -> int:
        MAX = 1e9
        dp = [[-1 for _ in range(len(grid[0]))] for _ in range(len(grid))]

        def rec(i,j):
            if i >= len(grid): return 0
            if dp[i][j] != -1: return dp[i][j]
            if i == len(grid)-1:
                dp[i][j] = grid[i][j]
                return dp[i][j]
            ans = MAX
            for nextj,val in enumerate(moveCost[grid[i][j]]):
                ans = min(ans,val+rec(i+1,nextj))
            ans += grid[i][j]
            dp[i][j] = ans
            return ans
        
        ans = MAX
        for i in range(len(grid[0])):
            ans = min(ans,rec(0,i))
        return ans

# bottom up DP
class Solution:
    def minPathCost(self, grid: list[list[int]], moveCost: list[list[int]]) -> int:
        dp = [[1e9 for _ in range(len(grid[0]))] for _ in range(len(grid))]

        for i in range(len(grid)-1,-1,-1):
            for j in range(len(grid[0])):
                if i == len(grid)-1:
                    dp[i][j] = grid[i][j]
                else:
                    for k in range(len(grid[0])):
                        dp[i][j] = min(dp[i][j],dp[i+1][k]+moveCost[grid[i][j]][k])
                    dp[i][j] += grid[i][j]
        return min(dp[0])

# Top down DP
class Solution:
    def minPathCost(self, grid: list[list[int]], moveCost: list[list[int]]) -> int:
        dp = [[1e9 for _ in range(len(grid[0]))] for _ in range(len(grid))]

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if i == 0:
                    dp[i][j] = grid[i][j]
                else:
                    for k in range(len(grid[0])):
                        dp[i][j] = min(dp[i][j],dp[i-1][k]+moveCost[grid[i-1][k]][j])
                    dp[i][j] += grid[i][j]
        return min(dp[-1])