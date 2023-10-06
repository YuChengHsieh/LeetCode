from collections import defaultdict
# Hash 
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        s_dict = defaultdict(int)
        for char in s:
            s_dict[char] += 1
        for char in t:
            s_dict[char] -= 1
            if s_dict[char] == -1: return char

# o(n) time, o(1) space
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        s_dict = [0]*26
        for char in s:
            s_dict[ord(char)-ord('a')] += 1
        for char in t:
            s_dict[ord(char)-ord('a')] -= 1
            if s_dict[ord(char)-ord('a')] == -1: return char

# o(n) time, o(1) space
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        c = 0
        for char in s:
            c ^= ord(char)
        for char in t:
            c ^= ord(char)
        return chr(c)