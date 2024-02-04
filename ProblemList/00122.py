# # DP
# class Solution:
#     def maxProfit(self, prices: list[int]) -> int:
#         ans = 0
#         prices_len = len(prices)
#         DP = [1000000 for _ in range(prices_len+1)]
#         # DP[i] means the minimum from list price[:i-1]
#         for i in range(1,prices_len+1):
#             if prices[i-1] > DP[i-1]:
#                 # minimum will not change
#                 DP[i] = DP[i-1]
#                 # try to sell
#                 ans += prices[i-1]-DP[i]
#             DP[i] = prices[i-1]
#         return ans

# greedy
class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        ans = 0
        prices_len = len(prices)
        for i in range(1,prices_len):
            if prices[i] > prices[i-1]:
                # if today price > yesterday => sell (because can buy and sell at same day)
                ans += prices[i]-prices[i-1]
        return ans