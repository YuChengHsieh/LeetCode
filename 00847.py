# Use bit operation and BFS
from collections import deque
class Solution:
    def shortestPathLength(self, graph: list[list[int]]) -> int:
        # Use bit operation
        n = len(graph)
        visited = set()
        all_mask = (1 << n)-1
        queue = deque()

        for i in range(len(graph)):
            queue.append((i,1<<i,0))
            visited.add((i,1<<i))
        
        while len(queue) != 0:
            node,mask,cost = queue.popleft()
            if mask == all_mask: return cost

            for nextn in graph[node]:
                next_mask = mask | (1<<nextn)
                
                if (nextn,next_mask) not in visited:
                    visited.add((nextn,next_mask))
                    queue.append((nextn,next_mask,cost+1))