class Solution:
    def findChampion(self, n: int, edges: list[list[int]]) -> int:
        # topological sort
        root_set = set([i for i in range(n)])
        grid = [set() for i in range(n)]
        for i,j in edges:
            grid[i].add(j)
            if j in root_set: root_set.remove(j)
        
        return list(root_set)[0] if len(root_set) == 1 else -1
        