class Solution:
    def smallestSubsequence(self, s: str) -> str:
        # monotonic stack
        stack = []
        last_occ = {}
        occ = set()
        for i,char in enumerate(s):
            last_occ[char] = i
        for i,char in enumerate(s):
            if char not in occ:
                while stack and ord(char) < ord(stack[-1]) and last_occ[stack[-1]] > i:
                    occ.remove(stack.pop())
                stack.append(char)
                occ.add(char)
        return ''.join(stack)
        