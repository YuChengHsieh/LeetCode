# stack
# o(n) time + o(n) space
class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        s_stack = []; t_stack = []
        for char in s:
            if char == '#': 
                if len(s_stack) != 0:
                    s_stack.pop()
            else:
                s_stack.append(char)
        
        for char in t:
            if char == '#': 
                if len(t_stack) != 0:
                    t_stack.pop()
            else:
                t_stack.append(char)
        
        return s_stack == t_stack

# o(n) time + o(1) space
class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        idx = 0
        while idx < len(s):
            if s[idx] == '#':
                if idx == 0: s = s[idx+1:]
                else:  
                    s = s[:idx-1]+s[idx+1:]
                    idx -= 1
            else: idx += 1
        
        idx = 0
        while idx < len(t):
            if t[idx] == '#':
                if idx == 0: t = t[idx+1:]
                else: 
                    t = t[:idx-1]+t[idx+1:]
                    idx -= 1
            else: idx += 1
        return s==t