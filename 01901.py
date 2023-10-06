class Solution:
    def findPeakGrid(self, mat: list[list[int]]) -> list[int]:
        row_start,row_end,col_start,col_end= 0,len(mat)-1,0,len(mat[0])-1
        # row = True
        def check(row,col):
            if ((row-1 >= 0 and mat[row-1][col] < mat[row][col]) or row-1 < 0) and \
            ((row+1 < len(mat) and mat[row+1][col] < mat[row][col]) or row+1 >= len(mat)) and \
            ((col-1 >= 0 and mat[row][col-1] < mat[row][col]) or col-1 < 0) and \
            ((col+1 < len(mat[0]) and mat[row][col+1] < mat[row][col]) or col+1 >= len(mat[0])):
                return True
            else:
                return False
       
        while True:
            # if row:
            row_mid = row_start+(row_end-row_start)//2
            col_max,col_max_idx = 0,-1
            for i,num in enumerate(mat[row_mid]):
                if num > col_max:
                    col_max = num
                    col_max_idx = i
            if check(row_mid,col_max_idx):
                return row_mid,col_max_idx
            elif row_mid+1 < len(mat) and mat[row_mid+1][col_max_idx] > mat[row_mid][col_max_idx]:
                row_start = row_mid+1
            else:
                row_end = row_mid-1