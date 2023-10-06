class Solution:
    def shortestPathBinaryMatrix(self, grid: list[list[int]]) -> int:
        # BFS
        if grid[0][0] == 1: return -1
        dx = [ 0, 1, 1, 1, 0,-1,-1,-1]
        dy = [-1,-1, 0, 1, 1, 1, 0,-1]
        n = len(grid)
        queue = [(0,0,1)]

        while len(queue) != 0:
            x,y,step = queue.pop(0)
            if x == n-1 and y == n-1:
                return step
            for i in range(8):
                next_x,next_y = x+dx[i],y+dy[i]
                if next_x>=0 and next_x<n and next_y>=0 and next_y<n and grid[next_x][next_y] == 0:
                    grid[next_x][next_y] = 1
                    queue.append((next_x,next_y,step+1))
        return -1