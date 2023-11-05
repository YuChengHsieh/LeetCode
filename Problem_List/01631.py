import heapq
from numpy import inf
class Solution:
    def minimumEffortPath(self, heights: list[list[int]]) -> int:
        row,col = len(heights), len(heights[0])
        direction = [(1,0),(-1,0),(0,1),(0,-1)]
        dist = [[inf for i in range(col)] for _ in range(row)]
        dist[0][0] = 0
        min_heap = [(0,0,0)]

        while len(min_heap) != 0:
            effort,x,y = heapq.heappop(min_heap)

            if x == row-1 and y == col-1: return effort

            for dx,dy in direction:
                nextx,nexty = x+dx,y+dy

                if 0<=nextx<row and 0 <=nexty<col:
                    new_effort = max(effort,abs(heights[x][y]-heights[nextx][nexty]))

                    if new_effort < dist[nextx][nexty]:
                        dist[nextx][nexty] = new_effort
                        heapq.heappush(min_heap,(new_effort,nextx,nexty))