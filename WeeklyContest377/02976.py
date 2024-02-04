# floyd warshall
from numpy import inf
class Solution:
    def minimumCost(self, source: str, target: str, original: list[str], changed: list[str], cost: list[int]) -> int:
        dist = [[inf]*26 for _ in range(26)]
        n = len(original)
        
        for i in range(n):
            dist[ord(original[i])-ord('a')][ord(changed[i])-ord('a')] = min(dist[ord(original[i])-ord('a')][ord(changed[i])-ord('a')],cost[i])
        
        for k in range(26):
            for i in range(26):
                for j in range(26):
                    if i != j and dist[i][k] != inf and dist[k][j] != inf and dist[i][j] > dist[i][k]+dist[k][j]: dist[i][j] = dist[i][k]+dist[k][j]
        
        ans = 0
        for i in range(len(source)):
            if source[i] != target[i]: 
                if dist[ord(source[i])-ord('a')][ord(target[i])-ord('a')] == inf: return -1
                ans += dist[ord(source[i])-ord('a')][ord(target[i])-ord('a')]
        
        return ans