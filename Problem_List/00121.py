# DP
class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        ans = 0
        prices_len = len(prices)
        DP = [1000000 for _ in range(prices_len+1)]
        # DP[i] means the minimum from list price[:i-1]
        for i in range(1,prices_len+1):
            if prices[i-1] < DP[i-1]:
                # set the minimum for prices[:i]
                DP[i] = prices[i-1]
            else:
                # minimum will not change
                DP[i] = DP[i-1]
                # try to sell
                if prices[i-1]-DP[i] > ans:
                    ans = prices[i-1]-DP[i]
        return ans