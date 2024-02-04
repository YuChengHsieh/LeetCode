from collections import defaultdict
class Solution:
    def findMinHeightTrees(self, n: int, edges: list[list[int]]) -> list[int]:
        if n == 1: return [0]
        graph = defaultdict(set)

        for i,j in edges:
            graph[i].add(j)
            graph[j].add(i)
        
        leaves = []
        for i in range(n):
            if len(graph[i]) == 1: leaves.append((i,0))
        
        depth = -1; ans = []
        while len(leaves) != 0:
            node,cnt = leaves.pop(0)
            if len(graph[node]) != 0:
                parent = graph[node].pop()
                graph[parent].remove(node)

                if len(graph[parent]) == 1: 
                    leaves.append((parent,cnt+1))

            del graph[node]
            
            if cnt > depth: 
                depth = cnt
                ans = [node]
            else:
                ans.append(node)
        
        return ans
            
