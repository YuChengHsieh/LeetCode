from collections import defaultdict
# o(n^3) slower
class Solution:
    def longestStrChain(self, words: list[str]) -> int:
        hash = defaultdict(list)
        words.sort(key = lambda a: len(a))
        for i,word in enumerate(words):
            hash[len(word)].append((i,word))
        dp = [1 for _ in range(len(words))]
        
        def check(s1,s2):
            s2_idx = 0
            for char in s1:
                if s2[s2_idx] == char: 
                    s2_idx += 1
                    if s2_idx == len(s2): return True
            return False

        for i in range(len(words)):
            for j,word in hash[len(words[i])-1]:
                if check(words[i],word):
                    dp[i] = max(dp[i],dp[j]+1)
        return max(dp)

# o(n^2) faster
class Solution:
    def longestStrChain(self, words: list[str]) -> int:
        words.sort(key = lambda a: len(a))
        dp = {}
        max_len = 1
        for word in words:
            dp[word] = 1
            for i in range(len(word)):
                tmp_str = word[:i]+word[i+1:]
                if tmp_str in dp:
                    dp[word] = max(dp[word],dp[tmp_str]+1)
                    max_len = max(max_len,dp[word])
        return max_len