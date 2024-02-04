class Solution:
    def decodeAtIndex(self, s: str, k: int) -> str:
        stack = [0]
        # insert stacks 
        for char in s:
            if char.isdigit():
                stack.append(stack[-1]*int(char))
            else:
                stack.append(stack[-1]+1)
        ln = len(stack)
        while len(stack) != 0:
            k %= stack[-1]
            ln -= 1
            if k == 0 and s[ln-1].isalpha():
                return s[ln-1]
            stack.pop()