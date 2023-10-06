class Solution:
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        dp = [[[-1 for _ in range(maxMove)] for _ in range(n)] for _ in range(m)]
        def rec(r,c,move):
            if r<0 or c<0 or r>=m or c>=n: return 1
            elif move<0: return 0
            elif dp[r][c][move] != -1:
                return dp[r][c][move]
            ans = 0
            ans += rec(r-1,c,move-1)
            ans += rec(r+1,c,move-1)
            ans += rec(r,c-1,move-1)
            ans += rec(r,c+1,move-1)
            dp[r][c][move] = int(ans%(1e9 + 7))
            return dp[r][c][move]
        return rec(startRow,startColumn,maxMove-1)