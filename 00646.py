class Solution:
    def findLongestChain(self, pairs: list[list[int]]) -> int:
        pairs.sort(key=lambda i: i[0])
        dp = [1 for _ in range(len(pairs))]
        for i in range(len(pairs)):
            for j in range(i):
                if pairs[i][0] > pairs[j][1] and dp[i] < dp[j]+1:
                    dp[i] = dp[j]+1
        return max(dp)