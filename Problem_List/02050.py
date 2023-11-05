class Solution:
    def minimumTime(self, n: int, relations: list[list[int]], time: list[int]) -> int:
        graph = [[] for _ in range(n+1)]
        for i,j in relations:
            graph[j].append(i)
        
        mem = {}
        def dfs(i):
            if i in mem: return mem[i]
            t = 0 
            for nextn in graph[i]:
                t = max(dfs(nextn),t)
            mem[i] = t+time[i-1]
            return mem[i]
        
        ans = 0
        for i in range(n):
            if i+1 not in mem:
                ans = max(ans,dfs(i+1))
        return ans
