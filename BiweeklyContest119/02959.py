from numpy import inf
class Solution:
    def numberOfSets(self, n: int, maxDistance: int, roads: list[list[int]]) -> int:
        if n == 1: return 2
        
        def floyd_warshall(nodes):
            
            dist = [[inf]*n for _ in range(n)]
            for from_,to,val in roads:
                # if from_ not in nodes or to not in nodes: continue
                dist[from_][to] = min(dist[from_][to],val)
                dist[to][from_] = min(dist[to][from_],val)
            for i in nodes:
                for j in nodes:
                    for k in nodes:
                        if i != j and dist[i][j] > dist[i][k] + dist[k][j]: 
                            dist[i][j] = dist[i][k] + dist[k][j]
                            dist[j][i] = dist[i][k] + dist[k][j]
            
            for i in nodes:
                for j in nodes:
                    if i != j and dist[i][j] > maxDistance: 
                        return False
            
            return True
        
        ans = 0
        for mask in range(1 << n):
            nodes = []
            for i in range(n):
                if mask >> i & 1 == 0:
                    nodes.append(i)
            if floyd_warshall(nodes): ans += 1

        return ans