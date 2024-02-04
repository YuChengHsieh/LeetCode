class Solution:
    def maxValueOfCoins(self, piles: list[list[int]], k: int) -> int:
        dp = [[-1 for _ in range(k+1)] for _ in range(len(piles))]
        def rec(i,j):
            if i >= len(piles) or j == 0: return 0
            if dp[i][j] != -1: return dp[i][j]
            cur_max = 0
            ans = 0
            for l in range(len(piles[i])+1):
                if l > 0:
                    ans += piles[i][l-1]
                if j-l >= 0:
                    cur_max = max(cur_max,ans+rec(i+1,j-l))
                else:
                    break
            dp[i][j] = cur_max
            return cur_max
        return rec(0,k)
