class Solution:
    def searchMatrix(self, matrix: list[list[int]], target: int) -> bool:
        # two BST
        if len(matrix) == 1 and len(matrix[0]) == 1:
            return True if target == matrix[0][0] else False
        # first: search in row
        start = 0
        end = len(matrix)-1
        while start < end:
            mid = start + (end-start)//2
            if matrix[mid][0] == target:
                return True
            elif target > matrix[mid][0]:
                start = mid
            else:# target < matrix[mid][0]
                end = mid
            if end == start+1 and target > matrix[mid][0]:
                if target == matrix[end][0]:
                    return True
                start = end if target > matrix[end][0] else start
                break
        second_search = matrix[start]
        start = 0
        end = len(second_search) - 1
        
        while start < end:
            mid = start + (end-start)//2
            if second_search[mid] == target:
                return True
            elif target > second_search[mid]:
                start = mid
            else:# target < matrix[mid][0]
                end = mid
            # stuck
            if end == start+1 and target > second_search[mid] :
                return True if target == second_search[end] else False
        return False
if __name__ == '__main__':
    a = Solution()
    print(a.searchMatrix([[1,3,5,7],[10,11,16,20],[23,30,34,60]],5))
    print(a.searchMatrix([[1,3,5,7],[10,11,16,20],[23,30,34,60]],13))
    print(a.searchMatrix([[1],[3]],1))
    print(a.searchMatrix([[1,3,5]],1))
            
                