class Solution:
    def updateMatrix(self, mat: list[list[int]]) -> list[list[int]]:
        m,n = len(mat),len(mat[0])
        dp = [[1e9 for _ in range(n)] for _ in range(m)]
        queue = []
        dxy = [(1,0),(-1,0),(0,1),(0,-1)]
        for i in range(m):
            for j in range(n):
                if mat[i][j] == 0:
                    dp[i][j] = 0
                    queue.append((i,j))
        
        while len(queue) != 0:
            row,col = queue.pop(0)
            for drow, dcol in dxy:
                next_row,next_col = row+drow,col+dcol
                if 0<=next_row<m and 0<=next_col<n and dp[next_row][next_col] > dp[row][col]+1:
                    dp[next_row][next_col] = dp[row][col]+1
                    queue.append((next_row,next_col))
        return dp
        