class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        char = [0 for i in range(26)]
        max_cont = 0
        left,right = 0,0

        while right < len(s):
            if sum(char)- max(char) <= k:
                char[ord(s[right])-ord('A')] += 1
                max_cont = max(right-left,max_cont)
                right += 1
            else:
                char[ord(s[left])-ord('A')] -= 1
                left += 1
        else:
            if sum(char)- max(char) <= k:
                max_cont = max(right-left,max_cont)
        return max_cont