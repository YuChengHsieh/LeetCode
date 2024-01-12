class Solution:
    def findContentChildren(self, g: list[int], s: list[int]) -> int:
        if len(s) == 0: return 0
        s.sort(key = lambda i: -i)
        g.sort(key = lambda i: -i)
        
        s_idx = 0; ans = 0
        for cookie in g:
            if s[s_idx] >= cookie: 
                ans += 1
                s_idx += 1
                if s_idx == len(s): break
        return ans 