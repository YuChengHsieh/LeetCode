class Solution:
    def searchMatrix(self, matrix: list[list[int]], target: int) -> bool:
        m,n = len(matrix),len(matrix[0])
        for i in range(m):
            if matrix[i][0] > target: return False
            start = 0; end = n-1
            while start <= end:
                mid = start+(end-start)//2
                if matrix[i][mid] == target:
                    return True
                elif matrix[i][mid] < target:
                    start = mid+1
                else:
                    end = mid-1
        return False