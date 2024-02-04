class Solution:
    def minimumTimeToInitialState(self, word: str, k: int) -> int:
        n = len(word)
        
        idx = 0; cnt = 1;
        for i in range(k,n,k):
            if word[i:] == word[:n-i]: return cnt
            cnt += 1
        return cnt