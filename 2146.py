# BFS
# similar to 1162
class Solution:
    def highestRankedKItems(self, grid: list[list[int]], pricing: list[int], start: list[int], k: int) -> list[list[int]]:
        queue = [start]
        directions = ((1,0),(-1,0),(0,1),(0,-1))
        row_len,col_len = len(grid),len(grid[0])
        ans_list = [start] if grid[start[0]][start[1]] >= pricing[0] and grid[start[0]][start[1]] <= pricing[1] else []
        grid[start[0]][start[1]] = 0

        while len(queue) != 0:
            size = len(queue)
            # store possible pick value with same distance from start point
            tmp_list = []
            for i in range(size):
                row,col = queue.pop(0)
                for dx,dy in directions:
                    tmp_row = row+dx
                    tmp_col = col+dy
                    if tmp_row>=0 and tmp_row<row_len and tmp_col>=0 and tmp_col<col_len and grid[tmp_row][tmp_col] != 0:
                        queue.append((tmp_row,tmp_col))
                        if grid[tmp_row][tmp_col]>= pricing[0] and grid[tmp_row][tmp_col]<= pricing[1]:
                            tmp_list.append((tmp_row,tmp_col,grid[tmp_row][tmp_col]))
                        grid[tmp_row][tmp_col] = 0
            tmp_list.sort(key=lambda i: (i[2],i[0],i[1]))
            if len(ans_list)+len(tmp_list) <= k:
                ans_list.extend([(i[0],i[1]) for i in tmp_list])
            else:
                ans_list.extend([(i[0],i[1]) for i in tmp_list[:k-len(ans_list)]])
                break
        return ans_list