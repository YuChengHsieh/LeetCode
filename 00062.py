# # backtracking TLE
# class Solution:
#     def uniquePaths(self, m: int, n: int) -> int:
#         self.cnt = 0
#         self.m = m; self.n = n
#         self.rec(0,0)    
#         return self.cnt
#     def rec(self,row,col):
#         if row >= self.m or col >= self.n:
#             return 
#         if row == self.m-1 and col == self.n-1:
#             self.cnt += 1
#             return
#         self.rec(row+1,col)
#         self.rec(row,col+1)
#         return

# DP
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        cnt = 0
        DP = []
        for _ in range(m):
            DP.append([0 for _ in range(n)])
        
        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    DP[i][j] = 1
                elif i == 0:
                    DP[i][j] = DP[i][j-1]
                elif j == 0:
                    DP[i][j] = DP[i-1][j]
                else:
                    DP[i][j] = DP[i-1][j]+DP[i][j-1]    
        return DP[m-1][n-1]
    
if __name__ == '__main__':
    a = Solution()
    print(a.uniquePaths(23,12))
            