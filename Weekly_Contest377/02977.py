from collections import defaultdict
from numpy import inf
class Solution:
    def minimumCost(self, source: str, target: str, original: list[str], changed: list[str], cost: list[int]) -> int:
        
        # changed_dist = defaultdict(set)
        # cost_dist = defaultdict(set)
        dist = defaultdict(list)
        dist2 = defaultdict(list)
        m = len(source)
        n = len(original)
        
        for i in range(n):
            if changed[i] in dist2[original[i]]: 
                idx = dist2[original[i]].index(changed[i])
                dist[original[i]][idx][-1] = min(dist[original[i]][idx][-1],cost[i])
            else:
                dist[original[i]].append([changed[i],cost[i]])
                dist2[original[i]].append(changed[i])
        
        visited = set()
        def dfs(str_):
            visited.add(str_)
            for next_str,cost in dist[str_]:
                if next_str not in visited: dfs(next_str)
                
                for des_str,des_cost in dist[next_str]:
                    if des_str not in dist2[str_]: 
                        dist[str_].append([des_str,des_cost+cost])
                        dist2[str_].append(des_str)
                    else: 
                        idx = dist2[str_].index(des_str)
                        dist[str_][idx][-1] = min(dist[str_][idx][-1],des_cost+cost)
        
        
        for key in dist2.keys():
            if key not in visited: dfs(key)
        
        change_len = set([len(orig) for orig in original])
        mem = [-1 for _ in range(m)]
        
        def dfs(i):
            if i >= m: return 0
            if mem[i] != -1: return mem[i]

            cost = inf if source[i] != target[i] else dfs(i+1)
            for length in change_len:
                if i+length > m: continue
                if source[i:i+length] in dist:
                    if target[i:i+length] in set(dist2[source[i:i+length]]):
                        trans_cost = dist[source[i:i+length]][dist2[source[i:i+length]].index(target[i:i+length])][-1]
                        if trans_cost != inf:
                            cost = min(cost, trans_cost+dfs(i+length))
            mem[i] = cost
            return mem[i]
        
        return dfs(0) if dfs(0) != inf else -1