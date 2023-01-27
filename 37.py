class Solution:
    def solveSudoku(self, board: list[list[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        self.board = board
        self.win = False
        self.row = [[] for _ in range(9)]
        self.col = [[] for _ in range(9)]
        self.box = [[] for _ in range(9)]
        for row in range(9):
            for col in range(9):
                if self.board[row][col] != '.':
                    self.row[row].append(self.board[row][col])
                    self.col[col].append(self.board[row][col])
                    self.box[row//3*3+col//3].append(self.board[row][col])
        self.rec(0,0)
        print(self.board)
        
    def rec(self, row: int, col:int):
        # end condition
        if row == 9:
            self.win = True
            return
        # have num in this place
        if self.board[row][col] != '.':
            self.rec(row,col+1) if col < 8 else self.rec(row+1,0)
            return
    
        # don't have num in this place, guess
        num_list = set(self.row[row] + self.col[col] + self.box[row//3*3+col//3])
        for num in range(1,10):
            if str(num) not in num_list: #fill the last 
                self.row[row].append(str(num))
                self.col[col].append(str(num))
                self.box[row//3*3+col//3].append(str(num))
                self.board[row][col] = str(num)
                self.rec(row,col+1) if col < 8 else self.rec(row+1,0)
                if self.win: return
                self.row[row].pop()
                self.col[col].pop()
                self.box[row//3*3+col//3].pop()
                self.board[row][col] = '.'
        

if __name__ == '__main__':
    a = Solution()
    a.solveSudoku([["5","3",".",".","7",".",".",".","."],
                    ["6",".",".","1","9","5",".",".","."],
                    [".","9","8",".",".",".",".","6","."],
                    ["8",".",".",".","6",".",".",".","3"],
                    ["4",".",".","8",".","3",".",".","1"],
                    ["7",".",".",".","2",".",".",".","6"],
                    [".","6",".",".",".",".","2","8","."],
                    [".",".",".","4","1","9",".",".","5"],
                    [".",".",".",".","8",".",".","7","9"]])
    # a.solveSudoku([[".",".","9","7","4","8",".",".","."],
    #                ["7",".",".",".",".",".",".",".","."],
    #                [".","2",".","1",".","9",".",".","."],
    #                [".",".","7",".",".",".","2","4","."],
    #                [".","6","4",".","1",".","5","9","."],
    #                [".","9","8",".",".",".","3",".","."],
    #                [".",".",".","8",".","3",".","2","."],
    #                [".",".",".",".",".",".",".",".","6"],
    #                [".",".",".","2","7","5","9",".","."]])