class Solution:
    def searchMatrix(self, matrix: list[list[int]], target: int) -> bool:
        # two BST
        start = 0; end = len(matrix)-1

        while start <= end:
            mid = start + (end-start)//2
            if matrix[mid][0] == target:
                return True
            elif matrix[mid][0] < target:
                start = mid+1
            else:
                end = mid-1
        
        row = end
        start = 0; end = len(matrix[0])-1
        while start <= end:
            mid = start + (end-start)//2
            if matrix[row][mid] == target:
                return True
            elif matrix[row][mid] < target:
                start = mid+1
            else:
                end = mid-1
        
        return False

if __name__ == '__main__':
    a = Solution()
    print(a.searchMatrix([[1,3,5,7],[10,11,16,20],[23,30,34,60]],5))
    print(a.searchMatrix([[1,3,5,7],[10,11,16,20],[23,30,34,60]],13))
    print(a.searchMatrix([[1],[3]],1))
    print(a.searchMatrix([[1,3,5]],1))
            
                