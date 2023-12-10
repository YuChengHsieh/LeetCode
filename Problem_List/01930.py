class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        n = len(s)
        char_leftmost = [-1]*26
        char_rightmost = [-1]*26

        for i in range(n):
            if char_leftmost[ord(s[i])-ord('a')] == -1:
                char_leftmost[ord(s[i])-ord('a')] = i
        
        for i in range(n-1,-1,-1):
            if char_rightmost[ord(s[i])-ord('a')] == -1:
                char_rightmost[ord(s[i])-ord('a')] = i
        cnt = 0
        for i in range(26):
            if char_leftmost[i] == -1 or char_rightmost[i] == -1 or \
            char_leftmost[i] == char_rightmost[i]: continue
            tmp_set = set()
            for j in range(char_leftmost[i]+1,char_rightmost[i]):
                if s[j] not in tmp_set: 
                    tmp_set.add(s[j])
                    cnt += 1
        return cnt

