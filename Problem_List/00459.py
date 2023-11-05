class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        substr_lens = [i for i in range(1,len(s)//2+1) if len(s)%i == 0]
        for substr_len in substr_lens:
            sub_str = s[:substr_len]
            for i in range(substr_len,len(s),substr_len):
                if s[i:i+substr_len] != sub_str: break
            else:
                return True
        return False

class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        return s in (s + s)[1:-1]