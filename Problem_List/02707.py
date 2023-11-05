class Solution:
    def minExtraChar(self, s: str, dictionary: list[str]) -> int:
        dp = [100 for _ in range(len(s)+1)]
        dp[0] = 0
        dictionary = set(dictionary)
        for i in range(len(s)+1):
            for j in range(i):
                if s[j:i] in dictionary:
                    dp[i] = min(dp[j],dp[i])
                else:
                    dp[i] = min(dp[i],dp[j]+i-j)
        return dp[-1]