class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        ans = 0
        for i,char in enumerate(columnTitle[::-1]):
            ans += (ord(char)-ord('A')+1)*26**i
        return ans