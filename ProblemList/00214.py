# kmp
class Solution:
    def shortestPalindrome(self, s: str) -> str:
        new_s = s + '#' + s[::-1]
        lps = [0]*len(new_s)

        def get_lps():
            prev = 0; idx = 1
            while idx < len(new_s):
                if new_s[prev] == new_s[idx]:
                    lps[idx] = prev+1
                    idx += 1
                    prev += 1
                elif prev == 0:
                    idx += 1
                else:
                    prev = lps[prev-1]

        get_lps()
        return s[::-1][:len(s)-lps[-1]]+s