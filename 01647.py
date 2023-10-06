# o(n)+o(26^2)
class Solution:
    def minDeletions(self, s: str) -> int:
        hash = {}
        set_ = set()
        for char in s:
            if hash.get(char) is None: hash[char] = 0
            hash[char] += 1

        cnt = 0
        for val in hash.values():
            while val != 0 and val in set_:
                val -= 1
                cnt += 1
            if val > 0: set_.add(val)
        return cnt

# Much faster
from collections import Counter
class Solution:
    def minDeletions(self, s: str) -> int:
        cnt = 0
        a = Counter(s)
        print(a)
        set_ = set()
        for val in sorted(a.values(),reverse=True):
            while val != 0 and val in set_:
                val -= 1
                cnt += 1
            if val > 0: set_.add(val)
        return cnt

