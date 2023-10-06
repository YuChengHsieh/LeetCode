class Solution:
    def maximalNetworkRank(self, n: int, roads: list[list[int]]) -> int:
        graph = [set() for _ in range(n)]
        for i,j in roads:
            graph[i].add(j)
            graph[j].add(i)
        ans = 0
        for i in range(n):
            for j in range(i+1,n):
                ans = max(ans,len(graph[i])+len(graph[j])-1 if j in graph[i] and i in graph[j] else len(graph[i])+len(graph[j]))
        return ans
        