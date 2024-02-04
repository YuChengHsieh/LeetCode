class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if len(s) == 0: return True
        s_idx = 0
        for char in t:
            if s[s_idx] == char: 
                s_idx += 1
                if s_idx == len(s): return True
        return False