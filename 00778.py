from numpy import inf
import heapq
class Solution:
    def swimInWater(self, grid: list[list[int]]) -> int:
        row,col = len(grid),len(grid[0])
        directions = [(1,0),(-1,0),(0,1),(0,-1)]
        dist = [[inf for _ in range(col)] for _ in range(row)]
        dist[0][0] = grid[0][0]
        min_heap = [(grid[0][0],0,0)]

        while len(min_heap) != 0:
            cost, x, y = heapq.heappop(min_heap)
            if x == row-1 and y == col-1: return cost
            for dx,dy in directions:
                nx,ny = x+dx,y+dy
                if 0<=nx<row and 0<=ny<col: 
                    new_cost = max(cost,grid[nx][ny])

                    if new_cost < dist[nx][ny]:
                        dist[nx][ny] = new_cost
                        heapq.heappush(min_heap,(new_cost,nx,ny))

class Solution:
    def swimInWater(self, grid: list[list[int]]) -> int:
        row,col = len(grid),len(grid[0])
        directions = [(1,0),(-1,0),(0,1),(0,-1)]
        min_heap = [(grid[0][0],0,0)]
        visited = set()

        while len(min_heap) != 0:
            cost, x, y = heapq.heappop(min_heap)
            if x == row-1 and y == col-1: return cost
            for dx,dy in directions:
                nx,ny = x+dx,y+dy
                if 0<=nx<row and 0<=ny<col and (nx,ny) not in visited: 
                    visited.add((nx,ny))
                    heapq.heappush(min_heap,(max(cost,grid[nx][ny]),nx,ny))

