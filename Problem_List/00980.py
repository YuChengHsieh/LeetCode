# list all posibilities
class Solution:
    def uniquePathsIII(self, grid: list[list[int]]) -> int:
        visited = [[False for _ in range(len(grid[0]))] for _ in range(len(grid))]
        self.cnt = 0
        def rec(i,j):
            if i<0 or i>=len(grid) or j<0 or j>=len(grid[0])\
             or visited[i][j] or grid[i][j] == -1:
                return 
            
            if grid[i][j] == 2:
                for i in range(len(grid)):
                    for j in range(len(grid[0])):
                        if grid[i][j] == -1 or grid[i][j] == 2:
                            continue
                        elif not visited[i][j]:
                            return
                self.cnt += 1
                return
            visited[i][j] = True
            rec(i+1,j)
            rec(i-1,j)
            rec(i,j+1)
            rec(i,j-1)
            visited[i][j] = False
            return
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    rec(i,j)
                    break
        
        return self.cnt