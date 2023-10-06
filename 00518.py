# DP
class Solution:
    def change(self, amount: int, coins: list[int]) -> int:
        # DP
        dp = [0 for _ in range(amount+1)]
        dp[0] = 1
        for coin in coins:
            for i in range(coin,amount+1):
                dp[i] += dp[i-coin]
        return dp[-1]

# Recursive + memorization
class Solution:
    def change(self, amount: int, coins: list[int]) -> int:
        dp = [ [ -1 for _ in range(amount+1)] for _ in range(len(coins))]
        def rec(amount,i):
            if i >= len(coins) or amount < 0: return 0
            if amount == 0: return 1
            if dp[i][amount] != -1: return dp[i][amount]
            cur_num = rec(amount-coins[i],i)
            cur_num += rec(amount,i+1)
            dp[i][amount] = cur_num
            return cur_num
        return rec(amount,0)