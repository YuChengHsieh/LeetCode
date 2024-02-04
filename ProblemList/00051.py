# class Solution:
#     def solveNQueens(self, n: int) -> list[list[str]]:
#         self.n = n
#         self.ans = []
#         self.rec(0,[])
#         return self.ans
        
#     def valid(self, row:int, col:int, queen_list:list):
#         for queen_row,queen_col in enumerate(queen_list):
#             if col == queen_col or row-col == queen_row-queen_col or\
#                 row+col == queen_row+queen_col:
#                     return False
#         return True
    
#     def rec(self, row:int, queen_list: list):
#         for col in range(self.n):
#             if self.valid(row,col,queen_list):
#                 queen_list.append(col)
#                 if row == self.n-1:
#                     list_str = []
#                     for r in range(self.n):
#                         tmp_str = ''
#                         for c in range(self.n):
#                             tmp_str = tmp_str+'Q' if c == queen_list[r] else tmp_str+'.'
#                         list_str.append(tmp_str)
#                     self.ans.append(list_str)
#                 else:
#                     self.rec(row+1,queen_list)
#                 queen_list.pop()

#         return

# Faster solution o(1) in isvalid
class Solution:
    def solveNQueens(self, n: int) -> int:
        self.n = n
        self.ans = []
        self.cond1,self.cond2,self.cond3 = {},{},{} #col, diagonal(positive slope), diagonal(negative slope)
        self.row = {} #remember col in every row
        self.rec(0)
        return self.ans
        
    def rec(self, row: int):
        for col in range(self.n):
             if self.cond1.get(col) is None and self.cond2.get(row-col) is None and \
                self.cond3.get(row+col) is None :
                
                self.row[row] = col
                self.cond1[col],self.cond2[row-col],self.cond3[row+col] = 1,1,1
                if row == self.n-1:
                    list_str = []
                    for r in range(self.n):
                        tmp_str = ''
                        for c in range(self.n):
                            tmp_str = tmp_str+'Q' if c == self.row.get(r) else tmp_str+'.'
                        list_str.append(tmp_str)
                    self.ans.append(list_str)
                else: 
                    self.rec(row+1)
                
                self.cond1.pop(col)
                self.cond2.pop(row-col)
                self.cond3.pop(row+col)
        return

if __name__ == '__main__':
    a =Solution()
    print(a.solveNQueens(5))