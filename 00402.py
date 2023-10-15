class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        # monotonic stack
        if len(num) == k: return '0'
        stack = []
        for i,char in enumerate(num):
            while stack and int(char) < int(stack[-1]) and len(stack)+len(num)-i > len(num)-k:
                stack.pop()
            if len(stack) < len(num)-k:
                stack.append(char)
        ans = ''.join(stack)
        if set(ans) == set('0'): return '0'
        while ans[0] == '0':
            ans = ans[1:]
        return ans
