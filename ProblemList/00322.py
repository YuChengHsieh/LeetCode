class Solution:
    def coinChange(self, coins: list[int], amount: int) -> int:
        if amount == 0: return 0
        dp = [1e9 for i in range(amount+1)]
        dp[0] = 0
        for i in range(1,amount+1):
            for coin in coins:
                if i-coin>=0: dp[i] = min(dp[i],dp[i-coin]+1)
        return -1 if dp[-1] == 1e9 else dp[-1]