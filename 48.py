# my sol
# class Solution:
#     def rotate(self, matrix: list[list[int]]) -> None:
#         """
#         Do not return anything, modify matrix in-place instead.
#         """
        
#         pos_dict = {}
#         matrix_len = len(matrix)
#         for i in range(matrix_len ):
#             for j in range(matrix_len):
#                 if pos_dict.get((i,j)) is not None:
#                     val = pos_dict.get((i,j))
#                 else:
#                     val = matrix[i][j]
#                 # swap
#                 tmp_val = matrix[j][matrix_len -1-i]
#                 matrix[j][matrix_len -1-i] = val
                
#                 # save address
#                 pos_dict[(j,matrix_len -1-i)] = tmp_val
                
# easy sol
class Solution:
    def rotate(self, matrix: list[list[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        matrix_len = len(matrix)
        for i in range(matrix_len):
            for j in range(i+1,matrix_len):
                tmp = matrix[j][i]
                matrix[j][i] = matrix[i][j]
                matrix[i][j] = tmp
        
        for i in range(matrix_len):
            for j in range(matrix_len//2):
                tmp = matrix[i][matrix_len-1-j]
                matrix[i][matrix_len-1-j] = matrix[i][j]
                matrix[i][j] = tmp
        
        # print(matrix)
if __name__ == '__main__':
    a = Solution()
    print(a.rotate([[1,2,3],[4,5,6],[7,8,9]]))
    print(a.rotate([[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]))