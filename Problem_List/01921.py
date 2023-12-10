# sort
class Solution:
    def eliminateMaximum(self, dist: list[int], speed: list[int]) -> int:
        n = len(dist)
        priority = [(i-1)//j+1 for i,j in zip(dist,speed)]
        priority.sort()
        for i in range(1,n+1):
            if i > priority[i-1]: return priority[i-1]
        return n 

# priority queue
import heapq
class Solution:
    def eliminateMaximum(self, dist: list[int], speed: list[int]) -> int:
        n = len(dist)
        pq = []
        for i in range(n):
            heapq.heappush(pq,(dist[i]-1)//speed[i]+1)
        for i in range(1,n+1):
            val = heapq.heappop(pq)
            if i > val: return val
        return n 