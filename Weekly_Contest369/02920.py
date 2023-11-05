class Solution:
    def maximumPoints(self, edges: list[list[int]], coins: list[int], k: int) -> int:
        mem = {}
        n = len(coins)
        graph = [[]*n for _ in range(n)]
        self.visited = set()

        for i,j in edges: 
            graph[i].append(j)
            graph[j].append(i)
        
        def rec(idx,times):
            if 10 ** 4 < 2 ** times: return 0
            if (idx,times) in mem: return mem[(idx,times)]
            self.visited.add(idx)
            ret1 = coins[idx]//(2**times)-k 
            for next_n in graph[idx]: 
                if next_n in self.visited: continue
                ret1 += rec(next_n,times)

            ret2 = coins[idx]//(2**(times+1))
            for next_n in graph[idx]: 
                if next_n in self.visited: continue
                ret2 += rec(next_n,times+1)
            self.visited.remove(idx)
            mem[(idx,times)] = max(ret1,ret2)
            return mem[(idx,times)]
        return rec(0,0)