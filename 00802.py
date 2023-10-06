# cycle detection
class Solution:
    def eventualSafeNodes(self, graph: list[list[int]]) -> list[int]:
        ans = set()
        visited = set()
        def DFS(node):
            # short cut
            if node in ans:
                return True
            elif node in visited:
                return False

            visited.add(node)
            for i in graph[node]:
                if not DFS(i): # check if next n is safe node or not, if not, current is not a safe node too
                    return False
                    
            else:
                # not a cycle
                ans.add(node)
                return True

        for i in range(len(graph)):
            if i not in visited:
                DFS(i)
        return sorted(list(ans))
