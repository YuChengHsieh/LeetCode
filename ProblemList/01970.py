# Binary search and BFS
class Solution:
    def latestDayToCross(self, row: int, col: int, cells: list[list[int]]) -> int:
        left = 0
        right = len(cells)

        def path_exist(day):
            tmp_cells = cells[:day]
            map = [[0 for _ in range(col)] for _ in range(row)]
            visited = [[False for _ in range(col)] for _ in range(row)]

            for i in range(len(tmp_cells)):
                map[tmp_cells[i][0]-1][tmp_cells[i][1]-1] = 1


            for i in range(col):
                if map[0][i] == 0 and not visited[0][i]:
                    queue = [(0,i)]
                    while len(queue) != 0:
                        cur_row, cur_col = queue.pop(0)
                        if cur_row < 0 or cur_row >= row or cur_col < 0 or cur_col >= col or visited[cur_row][cur_col] or map[cur_row][cur_col] == 1:
                            continue
                        
                        visited[cur_row][cur_col] = True
                        if cur_row == row-1:
                            return True
                        queue.append((cur_row-1,cur_col))
                        queue.append((cur_row+1,cur_col))
                        queue.append((cur_row,cur_col-1))
                        queue.append((cur_row,cur_col+1))
            
            return False
                

        # BS
        while left <= right:
            mid = left + (right-left)//2
            if not path_exist(mid):
                right = mid-1
            else:
                left = mid+1

        return right