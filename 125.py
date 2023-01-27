class Solution:
    def isPalindrome(self, s: str) -> bool:
        start = 0; end = len(s)-1
        while start <= end:
            s_start = s[start].lower()
            s_end= s[end].lower()
            if (ord(s_start)-ord('a')<0 or ord(s_start)-ord('a')>25) \
            and (ord(s_start)-ord('0')<0 or ord(s_start)-ord('0')>9):
                start += 1
            elif (ord(s_end)-ord('a')<0 or ord(s_end)-ord('a')>25) \
            and (ord(s_end)-ord('0')<0 or ord(s_end)-ord('0')>9):
                end -= 1
            else:
                if s_start == s_end:
                    start += 1
                    end -= 1
                else:
                    print(ord('{')-ord('a'),ord('{')-ord('0'))
                    return False
        return True