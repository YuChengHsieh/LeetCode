class Solution:
    def setZeroes(self, matrix: list[list[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        zerorows = set([])
        zerocols = set([])
        row_len = len(matrix)
        col_len = len(matrix[0])
        for i in range(row_len):
            for j in range(col_len):
                if matrix[i][j] == 0:
                    zerorows.add(i)
                    zerocols.add(j)

        for row in zerorows:
            for i in range(col_len):
                matrix[row][i] = 0
        
        for col in zerocols:
            for i in range(row_len):
                matrix[i][col] = 0
        
        print(matrix)

if __name__ == '__main__':
    a = Solution()
    a.setZeroes([[0,1]])
    a.setZeroes([[1,1,1],[1,0,1],[1,1,1]])
    a.setZeroes([[0,1,2,0],[3,4,5,2],[1,3,1,5]])