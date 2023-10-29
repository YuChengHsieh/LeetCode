class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        mem = {}
        def rec(start,end):
            if start >= end: return 0
            if (start,end) in mem: return mem[(start,end)]
            if s[start] == s[end]:
                mem[(start,end)] = rec(start+1,end-1)
                return mem[(start,end)]
            
            mem[(start,end)] = min(rec(start+1,end),rec(start,end-1))+1
            return mem[(start,end)]
        return len(s)-rec(0,len(s)-1)