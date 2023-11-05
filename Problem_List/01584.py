class Union_Find:
    def __init__(self,n):
        self.parents = [i for i in range(n)]
        self.weights = 0
        self.edge_count = 0
    def find(self,x):
        if x != self.parents[x]: self.parents[x] = self.find(self.parents[x])
        return self.parents[x]
    def union(self,w,a,b):
        r1 = self.find(a)
        r2 = self.find(b)
        if r1!=r2: # is disjoint set
            self.parents[r2] = r1
            self.weights += w
            self.edge_count += 1
import heapq
# Heap+Kruskal
class Solution:
    # Kruskal
    def minCostConnectPoints(self, points: list[list[int]]) -> int:
        if len(points) == 1: return 0
        edges = []
        visited = set()
        ans = 0
        uf = Union_Find(len(points))
        for i,(x1,y1) in enumerate(points):
            for j,(x2,y2) in enumerate(points[i+1:],i+1):
                heapq.heappush(edges,(abs(x2-x1)+abs(y2-y1),i,j))
        

        while uf.edge_count < len(points) - 1:
            pack = heapq.heappop(edges)
            uf.union(*pack)
        return uf.weights

from numpy import inf
# Heap+Prims
class Solution:
    def minCostConnectPoints(self, points: list[list[int]]) -> int:
        dist = [inf for i in range(len(points))]
        dist[0] = 0
        visited = set()
        min_heap = [(0,0)]
        ans = 0
        while len(min_heap) != 0 :
            cost, idx = heapq.heappop(min_heap)
            if idx in visited: continue
            visited.add(idx)
            ans += cost
            if len(visited) == len(points): return ans
            
            for i in range(len(points)):
                if i not in visited:
                    new_cost = abs(points[idx][0]-points[i][0]) + abs(points[idx][1]-points[i][1])
                    if new_cost < dist[i]:
                        dist[i] = new_cost
                        heapq.heappush(min_heap,(new_cost,i))