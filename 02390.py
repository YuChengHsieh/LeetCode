# much slower
class Solution:
    def removeStars(self, s: str) -> str:
        i = 0
        while i < len(s):
            if s[i] == '*':
                s = s[:i-1] + s[i+1:]
                i -= 2
            i += 1
        return s

# much faster by using stack
class Solution:
    def removeStars(self, s: str) -> str:
        stack = []
        for i in range(len(s)):
            if s[i] == '*':
                stack.pop()
            else:
                stack.append(s[i])
        return ''.join(stack)