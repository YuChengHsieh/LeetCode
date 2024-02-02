class Solution:
    def countOfPairs(self, n: int, x: int, y: int) -> list[int]:
        dp = [[0 for _ in range(n)] for _ in range(n)]
        max_ = max(x,y); min_ = min(x,y)
        if x != y: dp[max_-1][min_-1] = 1
        ans = [0]*n
        for i in range(n):
            for j in range(i-1,-1,-1):
                if j == i-1: dp[i][j] = 1
                else: dp[i][j] = min(dp[max_-1][min_-1]+abs(i-(max_-1))+abs(j-(min_-1)),dp[i][j+1]+1)
        # print(dp)
        
        ans = [0]*n
        for i in range(n):
            for j in range(n):
                if dp[i][j] == 0: continue
                ans[dp[i][j]-1] += 2
        return ans
                
                
                