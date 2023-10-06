class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        dp = [[0 for _ in range(len(text2)+1)] for _ in range(len(text1)+1)]

        for i in range(len(text1)):
            for j in range(len(text2)):
                if text1[i] == text2[j]: dp[i+1][j+1] = dp[i][j]+1
                else: dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1])
        print(dp)
        return dp[len(text1)][len(text2)]
    
# 1d 
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        dp = [0 for _ in range(len(text2)+1)]

        for i in range(len(text1)):
            cur = [0]
            for j in range(len(text2)):
                if text1[i] == text2[j]: cur.append(dp[j]+1)
                else: cur.append(max(cur[j],dp[j+1]))
            dp = cur
        return dp[-1]