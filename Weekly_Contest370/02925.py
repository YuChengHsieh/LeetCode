class Solution:
    def maximumScoreAfterOperations(self, edges: list[list[int]], values: list[int]) -> int:
        # dfs
        n = len(values)
        graph = [set() for _ in range(n)]
        for i,j in edges:
            graph[i].add(j)
            graph[j].add(i)
        
        
        ans = 0
        def dfs(node,parent):
            if len(graph[node]) == 1 and node != 0: return values[node]
            sum_ = 0
            for nextn in graph[node]:
                if nextn == parent: continue
                sum_ += dfs(nextn,node)
            return min(sum_,values[node])
           
        return sum(values)-dfs(0,0)
        