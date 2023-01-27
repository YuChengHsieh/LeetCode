# o(n) sliding window and hash map => tackle permutation
class Solution:
    def findAnagrams(self, s: str, p: str) -> list[int]:
        s_len = len(s); p_len = len(p)
        s_list = [0 for _ in range(26)]
        p_list = [0 for _ in range(26)]
        for char in p:
            p_list[ord(char)-ord('a')] += 1
        
        ans = []
        cnt = -p_len
        # maintain a sliding window
        for idx in range(s_len):
            s_list[ord(s[idx])-ord('a')] += 1
            if cnt >= 0:
                s_list[ord(s[cnt])-ord('a')] -= 1
            if s_list == p_list:
                ans.append(cnt+1)
            cnt += 1
        return ans