class Solution:
    def totalNQueens(self, n: int) -> int:
        self.n = n
        self.cnt = 0
        self.cond1,self.cond2,self.cond3 = {},{},{} #col, diagonal(positive slope), diagonal(negative slope)
        self.rec(0)
        return self.cnt
        
    def rec(self, row: int):
        for col in range(self.n):
             if self.cond1.get(col) is None and self.cond2.get(row-col) is None and \
                self.cond3.get(row+col) is None :

                if row == self.n-1:
                    self.cnt += 1
                else: 
                    self.cond1[col],self.cond2[row-col],self.cond3[row+col] = 1,1,1
                    self.rec(row+1)
                    self.cond1.pop(col)
                    self.cond2.pop(row-col)
                    self.cond3.pop(row+col)
            
        return

if __name__ == '__main__':
    a = Solution()
    print(a.totalNQueens(4))
    print(a.totalNQueens(8))