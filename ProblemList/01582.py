class Solution:
    def numSpecial(self, mat: list[list[int]]) -> int:
        m,n = len(mat),len(mat[0])
        ones_row = [0]*m; ones_col = [0]*n
        for i in range(m):
            for j in range(n):
                if mat[i][j] == 1:
                    ones_row[i] += 1
                    ones_col[j] += 1
        
        cnt = 0
        for i in range(m):
            for j in range(n):
                if mat[i][j] == 1 and ones_row[i] == 1 and ones_col[j] == 1: cnt += 1
        
        return cnt