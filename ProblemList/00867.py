class Solution:
    def transpose(self, matrix: list[list[int]]) -> list[list[int]]:
        m,n = len(matrix), len(matrix[0])
        transpose_matrix = [[0]*m for _ in range(n)]
        for i in range(m):
            for j in range(n):
                transpose_matrix[j][i] = matrix[i][j]
        return transpose_matrix