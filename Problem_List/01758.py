class Solution:
    def minOperations(self, s: str) -> int:
        
        first = 0
        prev = '0'
        for i in range(len(s)):
            if s[i] == prev: 
                prev = '1' if s[i] == '0' else '0'
                first += 1
            else: prev = s[i]
        
        second = 0
        prev = '1'
        for i in range(len(s)):
            if s[i] == prev: 
                prev = '1' if s[i] == '0' else '0'
                second += 1
            else: prev = s[i]
        
        return min(first,second)