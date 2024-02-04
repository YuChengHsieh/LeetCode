class Solution:
    def validateBinaryTreeNodes(self, n: int, leftChild: list[int], rightChild: list[int]) -> bool:
        visited = set()
        def dfs(idx):
            if idx == -1: return True
            if idx in visited: return False
            visited.add(idx)
            return dfs(leftChild[idx]) and dfs(rightChild[idx])
        
        # find root
        not_root = set(leftChild+rightChild)
        if -1 in not_root: not_root.remove(-1)
        if n-len(not_root) != 1: return False
        for i in range(n):
            if i not in not_root:
                root = i
                break
        result = dfs(root)
        return False if len(visited) != n else result
        

class Solution:
    def validateBinaryTreeNodes(self, n: int, leftChild: list[int], rightChild: list[int]) -> bool:
        visited = set()
        def dfs(idx):
            if idx == -1: return True
            if idx in visited: return False
            visited.add(idx)
            return dfs(leftChild[idx]) and dfs(rightChild[idx])
        
        # find root
        not_visited = set([i for i in range(n)])
        for num in leftChild:
            if num in not_visited:
                not_visited.remove(num)

        for num in rightChild:
            if num in not_visited:
                not_visited.remove(num)

        if len(not_visited) != 1: return False
        result = dfs(list(not_visited)[0])
        return False if len(visited) != n else result
         