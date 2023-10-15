# DP o(n^2)
class Solution:
    def getWordsInLongestSubsequence(self, n: int, words: list[str], groups: list[int]) -> list[str]:
        ans = []
        n = len(groups)
        dp = [[] for _ in range(n)]
        
        def check(word1,word2):
            dif = 0
            for i in range(len(word1)):
                if word1[i] != word2[i]: dif += 1
            return dif <= 1
                
        for i in range(n):
            dp[i] = [words[i]]
            for j in range(i):
                if len(dp[j]) >= len(dp[i]) and len(words[j]) == len(words[i]) \
                and check(words[i],words[j]) and groups[j] != groups[i]:
                    dp[i] = dp[j].copy() + [words[i]]
        
        ans = []
        for i in range(n):
            if len(dp[i]) > len(ans):
                ans = dp[i]
        
        return ans
                    
        