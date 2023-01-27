class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s[::-1]
        first = False
        cnt = 0
        for char in s:
            if char == ' ':
                if first:
                    break
                continue
            first = True
            cnt += 1
        
        return cnt
        
if __name__ == '__main__':
    a = Solution()
    print(a.lengthOfLastWord("Hello World"))
    print(a.lengthOfLastWord("   fly me   to   the moon  "))
    print(a.lengthOfLastWord("a"))
            
            