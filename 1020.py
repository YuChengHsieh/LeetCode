class Solution:
    def numEnclaves(self, grid: list[list[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        def dfs(i,j):
            if i<0 or i>= rows or j<0 or j>=cols or grid[i][j] == 0:
                return
            grid[i][j] = 0
            dfs(i-1,j)
            dfs(i+1,j)
            dfs(i,j-1)
            dfs(i,j+1)
            return


        for i in range(rows):
            for j in range(cols):
                if i == 0 or i == rows-1 or j == 0 or j == cols-1:
                    dfs(i,j)
        
        ans = 0
        for i in range(rows):
            for j in range(cols):
                ans += grid[i][j]

        return  ans 