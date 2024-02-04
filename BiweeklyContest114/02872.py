class Solution:
    def maxKDivisibleComponents(self, n: int, edges: list[list[int]], values: list[int], k: int) -> int:
        # firstly find the root
        
        graph = [set() for _ in range(n)]
        
        for i,j in edges:
            graph[i].add(j)
            graph[j].add(i)
        
        self.visited = set()
        self.ans = 0
        def rec(idx):
            self.visited.add(idx)
            cur_val = values[idx]
            for nextn in graph[idx]:
                if nextn in self.visited: continue
                ret = rec(nextn)
                if ret == 0: self.ans += 1
                else: cur_val += ret
            return cur_val%k
        rec(0)
        return self.ans+1
            
        
        
        