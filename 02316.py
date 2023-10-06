# DFS
class Solution:
    def countPairs(self, n: int, edges: list[list[int]]) -> int:
        self.graph = [ set() for _ in range(n)]

        for a,b in edges:
            self.graph[a].add(b)
            self.graph[b].add(a)
        
        self.cnt = 0 # # of connected points in a sub graph
        self.remain_node = set([i for i in range(n)])
        ans = 0
        while len(self.remain_node) != 0:
            self.cnt = 0
            remain_node_len = len(self.remain_node)
            # indexing a set
            for i in self.remain_node:
                self.dfs(i)
                break
            ans += (remain_node_len - self.cnt)*self.cnt
        return ans

    def dfs(self,node):
            if node not in self.remain_node: return
            self.remain_node.remove(node)
            self.cnt+=1
            for nextn in self.graph[node]:
                self.dfs(nextn)
            return