class Solution:
    def maximumLength(self, s: str) -> int:
        left = right = 0
        n = len(s)
        mem = [[0]*(n+1) for i in range(26)]
        max_idx = [0]*26
        while left < n:
            if right < n and s[right] == s[left]: right += 1
            else:
                mem[ord(s[left])-ord('a')][right-left] += 1
                max_idx[ord(s[left])-ord('a')] = max(max_idx[ord(s[left])-ord('a')],right-left)
                left = right
        
        max_sublen = -1
        for i in range(26):
            prev = 0
            for j in range(max_idx[i],0,-1):
                cur_subnum = mem[i][j]+prev
                if cur_subnum >= 3:
                    max_sublen = max(max_sublen,j)
                    break
                prev = cur_subnum*2
        
        return max_sublen