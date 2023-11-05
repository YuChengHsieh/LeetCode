from numpy import inf
class Solution:
    def cherryPickup(self, grid: list[list[int]]) -> int:
        dp = [[[-1 for _ in range(len(grid))] for _ in range(len(grid[0]))] for _ in range(len(grid))]
        
        def rec(r1,c1,r2):
            c2 = r1+c1-r2
            if r1>=len(grid) or r2>= len(grid)\
            or c1>=len(grid[0]) or c2>= len(grid[0])\
            or grid[r1][c1] == -1 or grid[r2][c2] == -1:
                return -inf
            if dp[r1][c1][r2] != -1: return dp[r1][c1][r2]
            if r1 == len(grid)-1 and c1 == len(grid[0])-1: return grid[r1][c1]
            ans = max(rec(r1+1,c1,r2+1),rec(r1+1,c1,r2),rec(r1,c1+1,r2+1),rec(r1,c1+1,r2))
            ans += grid[r1][c1]
            if r1!=r2: ans += grid[r2][c2]
            dp[r1][c1][r2] = ans
            return dp[r1][c1][r2]

        ans = rec(0,0,0)
        return 0 if ans == -inf else ans
