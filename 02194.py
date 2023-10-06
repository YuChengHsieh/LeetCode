class Solution:
    def cellsInRange(self, s: str) -> list[str]:
        ans = []
        for i in range(ord(s[3])-ord(s[0])+1):
            for j in range(int(s[1]),int(s[4])+1):
                ans.append(f'{chr(ord(s[0])+i)}{j}')
        return ans