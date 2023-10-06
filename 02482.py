class Solution:
    def onesMinusZeros(self, grid: list[list[int]]) -> list[list[int]]:
        m,n = len(grid),len(grid[0])
        ones_row = [0]*m; ones_col = [0]*n
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    ones_row[i] += 1
                    ones_col[j] += 1
        diff = [[-1 for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                diff[i][j] = ones_row[i]+ones_col[j]-(m-ones_row[i])-(n-ones_col[j])
        return diff