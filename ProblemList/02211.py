class Solution:
    def countCollisions(self, directions: str) -> int:
        n = len(directions)
        stack = []
        cnt = 0

        for i in range(n):
            if directions[i] == 'L':
                if stack:
                    if stack[-1] == 'R': 
                        stack.pop()
                        cnt += 2
                        while stack and stack[-1] != 'S': 
                            stack.pop()
                            cnt += 1
                        if len(stack) == 0: stack.append('S')
                    else: cnt += 1
            elif directions[i] == 'S':
                while stack and stack[-1] != 'S': 
                    stack.pop()
                    cnt += 1 
                if len(stack) == 0: stack.append('S')
            else:
                stack.append('R')
        return cnt
                
class Solution:
    def countCollisions(self, directions: str) -> int:
        n = len(directions)
        l,r = 0, n-1
        while l < n and directions[l] == 'L':
            l += 1
        while r >= 0 and directions[r] == 'R':
            r -= 1
        
        cnt = 0
        for i in range(l,r+1):
            if directions[i] != 'S':
                cnt += 1
                
        return cnt