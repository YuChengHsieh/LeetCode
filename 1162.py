# own thought o(n^3)
# class Solution:
#     def maxDistance(self, grid: list[list[int]]) -> int:
#         water_pos_list = []
#         water_cnt = 0
#         row_len,col_len = len(grid),len(grid[0])
#         for i in range(row_len):
#             for j in range(col_len):
#                 if grid[i][j] == 1:
#                     water_pos_list.append((i,j))
#                     water_cnt += 1
        
#         # no water or all water
#         if water_cnt == 0 or water_cnt == row_len*col_len:
#             return -1

#         cnt = row_len*col_len-water_cnt
#         max_distance = 1

#         while True:
#             # expand from water point
#             for row,col in water_pos_list:
#                 for i in range(max_distance):
#                     # upper left
#                     if row-i>=0 and col-max_distance+i>=0 and grid[row-i][col-max_distance+i] == 0:
#                         grid[row-i][col-max_distance+i]  = 1
#                         cnt -= 1
#                     # upper right
#                     if row-max_distance+i>=0 and col+i<col_len and grid[row-max_distance+i][col+i]  == 0:
#                         grid[row-max_distance+i][col+i]  = 1
#                         cnt -= 1
#                     # lower right
#                     if row+i<row_len and col+max_distance-i<col_len and grid[row+i][col+max_distance-i]  == 0:
#                         grid[row+i][col+max_distance-i]  = 1
#                         cnt -= 1
#                     # lower left
#                     if row+max_distance-i<row_len and col-i>=0 and grid[row+max_distance-i][col-i]  == 0:
#                         grid[row+max_distance-i][col-i]  = 1
#                         cnt -= 1
#             if cnt == 0:
#                 break
#             max_distance += 1
#         return max_distance

# BFS o(n^2)
class Solution:
    def maxDistance(self, grid: list[list[int]]) -> int:
        queue = []
        row_len,col_len = len(grid),len(grid[0])
        for i in range(row_len):
            for j in range(col_len):
                if grid[i][j] == 1:
                    queue.append((i,j))
        
        # # no water or all water
        if len(queue) == 0 or len(queue) == row_len*col_len:
            return -1
        
        max_distance = 0
        direction = ((-1,0),(1,0),(0,-1),(0,1))
        while True:
            size = len(queue)
            for _ in range(size):
                row,col = queue.pop(0)
                for dx, dy in direction:
                    tmp_row = row+dx
                    tmp_col = col+dy
                    if tmp_row>=0 and tmp_row<row_len and tmp_col>=0 and tmp_col<col_len and grid[tmp_row][tmp_col] == 0:
                        grid[tmp_row][tmp_col] = 1
                        queue.append((tmp_row,tmp_col))
            if len(queue) == 0:
                break
            max_distance += 1
        return max_distance