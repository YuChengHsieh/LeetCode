class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        dp = [[0 for _ in range(len(word2)+1)] for _ in range(len(word1)+1)]
        
        sum_ = 1
        for i in range(len(word1)):
            dp[i+1][0] = sum_ 
            sum_ += 1

        sum_ = 1
        for i in range(len(word2)):
            dp[0][i+1] = sum_ 
            sum_ += 1
        
        for i in range(len(word1)):
            for j in range(len(word2)):
                if word1[i] == word2[j]: dp[i+1][j+1] = dp[i][j]
                else: dp[i+1][j+1] = min(dp[i+1][j], dp[i][j+1])+1
        
        return dp[len(word1)][len(word2)]

# 1D
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        dp = [0 for _ in range(len(word2)+1)]
        
        sum_ = 1
        for i in range(len(word2)):
            dp[i+1] = sum_ 
            sum_ += 1

        
        for i in range(len(word1)):
            cur = [dp[0]+1]
            for j in range(len(word2)):
                if word1[i] == word2[j]: cur.append(dp[j])
                else: cur.append(min(cur[j], dp[j+1])+1)
            dp = cur
        
        return cur[-1]