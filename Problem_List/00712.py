class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        dp = [[0 for _ in range(len(s2)+1)] for _ in range(len(s1)+1)]
        sum = 0
        for i in range(len(s1)):
            dp[i+1][0] = dp[i][0] + ord(s1[i])
        for i in range(len(s2)):
            dp[0][i+1] = dp[0][i] + ord(s2[i])
        
        for i in range(len(s1)):
            for j in range(len(s2)):
                if s1[i] == s2[j]:
                    dp[i+1][j+1] = dp[i][j]
                else:
                    dp[i+1][j+1] = min(dp[i+1][j]+ord(s2[j]),dp[i][j+1]+ord(s1[i]))
        return dp[len(s1)][len(s2)]

# 1d
class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        dp = [0 for _ in range(len(s2)+1)]

        for i in range(len(s2)):
            dp[i+1] = dp[i] + ord(s2[i])
        
        for i in range(len(s1)):
            cur = [dp[0]+ord(s1[i])]
            for j in range(len(s2)):
                if s1[i] == s2[j]:
                    cur.append(dp[j])
                else:
                    cur.append(min(cur[j]+ord(s2[j]),dp[j+1]+ord(s1[i])))
            dp = cur
        return dp[-1]