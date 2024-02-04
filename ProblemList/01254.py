# class Solution:
#     def closedIsland(self, grid: list[list[int]]) -> int:
#         width = len(grid[0])
#         height = len(grid)
#         visited = [[False]*width for _ in range(height) ]

#         def dfs(i,j,wall):
#             visited[i][j] = True
#             if i-1 >= 0:
#                 if grid[i-1][j] != 1 and not visited[i-1][j]:
#                     wall=dfs(i-1,j,wall)
#             else:
#                 wall = True
            
#             if i+1 < height:
#                 if grid[i+1][j] != 1 and not visited[i+1][j]:
#                     wall=dfs(i+1,j,wall)
#             else:
#                 wall = True
            
#             if j-1 >= 0:
#                 if grid[i][j-1] != 1 and not visited[i][j-1]:
#                     wall=dfs(i,j-1,wall)
#             else:
#                 wall = True

#             if j+1 < width:
#                 if grid[i][j+1] != 1 and not visited[i][j+1]:
#                     wall=dfs(i,j+1,wall)
#             else:
#                 wall = True
#             return wall

#         cnt = 0
#         for i in range(height):
#             for j in range(width):
#                 if grid[i][j] != 1 and not visited[i][j]:
#                     count = dfs(i,j,False)
#                     if not count:
#                         cnt += 1
#         return cnt

class Solution:
    def closedIsland(self, grid: list[list[int]]) -> int:
        width = len(grid[0])
        height = len(grid)

        def dfs(row,col):
            if row<0 or row >= height or col<0 or col >= width:
                return False
            if grid[row][col] == 1:
                return True
            grid[row][col] = 1
            up = dfs(row-1,col)
            down = dfs(row+1,col)
            left = dfs(row,col-1)
            right = dfs(row,col+1)
            return up and down and right and left
        
        cnt = 0
        for i in range(height):
            for j in range(width):
                if grid[i][j] != 1:
                    count = dfs(i,j)
                    if count:
                        cnt += 1
        return cnt