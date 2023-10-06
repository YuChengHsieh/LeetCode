class Solution:
    def checkValid(self, matrix: list[list[int]]) -> bool:
        n = len(matrix)
        row = [set([i+1 for i in range(n)]) for _ in range(n)]
        col = [set([i+1 for i in range(n)]) for _ in range(n)]
        print(row)
        for idx_row,i in enumerate(matrix):
            for idx_col,j in enumerate(i):
                try:
                    row[idx_row].remove(j)
                except:
                    return False
                try:
                    col[idx_col].remove(j)
                except:
                    return False
        return True

class Solution:
    def checkValid(self, matrix: list[list[int]]) -> bool:
        n = len(matrix)
        row = [set() for _ in range(n)]
        col = [set() for _ in range(n)]

        for i in range(n):
            for j in range(n):
                if matrix[i][j] in row[i] or matrix[i][j] in col[j]: return False
                row[i].add(matrix[i][j])
                col[j].add(matrix[i][j])
        return True
