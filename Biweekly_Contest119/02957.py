class Solution:
    def removeAlmostEqualCharacters(self, word: str) -> int:
        prev = ' '
        ans = 0
        change = True
        for char in word:
            if not change and abs(ord(prev)-ord(char)) <= 1:
                ans += 1
                change = True
            else:
                change = False
            prev = char
        return ans
                