class Solution:
    def firstCompleteIndex(self, arr: list[int], mat: list[list[int]]) -> int:
        m,n = len(mat),len(mat[0])
        painted_row = [0]*m; painted_col = [0]*n
        look_up = {}
        for i in range(m):
            for j in range(n):
                look_up[mat[i][j]] = (i,j)
        for idx,i in enumerate(arr):
            row,col = look_up[i]
            painted_row[row] += 1
            painted_col[col] += 1
            if painted_row[row] == n or painted_col[col] == m:
                return idx
