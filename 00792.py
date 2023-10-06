from collections import defaultdict
class Solution:
    def numMatchingSubseq(self, s: str, words: list[str]) -> int:
        def isSeq(s,word):
            idx = 0
            for char in s:
                if char == word[idx]: 
                    idx += 1
                    if idx == len(word): return True
            return False
        words_cnt = defaultdict(int)
        for word in words:
            words_cnt[word] += 1
        
        ans = 0
        for key,val in words_cnt.items():
            # is subsquence?
            if isSeq(s,key): ans += val
        return ans

