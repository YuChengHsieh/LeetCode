class Solution:
    def minimumOperationsToMakeEqual(self, x: int, y: int) -> int:
        # BFS        
        visited = set()
        q = [(x,0)]
        
        while q:
            num,cnt = q.pop(0)
            if num == y: return cnt
            if num > y and num%11 == 0 and num//11 not in visited: 
                visited.add(num//11)
                q.append((num//11,cnt+1))
            if num > y and num%5 == 0 and num//5 not in visited:
                visited.add(num//5)
                q.append((num//5,cnt+1))
            if num > y and num-1 not in visited:
                visited.add(num-1)
                q.append((num-1,cnt+1))
            if num+1 not in visited:
                visited.add(num+1)
                q.append((num+1,cnt+1))