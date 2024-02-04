from collections import defaultdict
class Solution:
    def collectTheCoins(self, coins: list[int], edges: list[list[int]]) -> int:
        if len(coins) == 1: return 0
        graph = defaultdict(set)
        n = len(coins)
        for i,j in edges:
            graph[i].add(j)
            graph[j].add(i)

        for i in range(n):
            if i not in graph: continue
            while len(graph[i]) == 1 and coins[i] == 0: 
                parent = graph[i].pop()
                graph[parent].remove(i)
                del graph[i]
                i = parent
        
        # collect at distance at most "2" 
        for _ in range(2):
            leaves = [i for i in graph.keys() if len(graph[i]) == 1]
            for i in leaves:
                if i not in graph: continue
                parent = graph[i].pop()
                graph[parent].remove(i)
                del graph[i]
                if len(graph) < 2: return 0
    
        return 2*(len(graph)-1) 
