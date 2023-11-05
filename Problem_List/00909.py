# BFS
class Solution:
    def snakesAndLadders(self, board: list[list[int]]) -> int:
        self.len = len(board)
        self.terminal_num = self.len*self.len
        move_ptDict = [-1 for _ in range(self.terminal_num+1)]
        move_ptDict[1] = 0
        queue = [1]
        
        while(len(queue) != 0):
            cur = queue.pop(0)
            for next in range(cur+1,min(cur+7,self.terminal_num+1)):
                row,col = self.num2position(next)
                des = board[row][col] if board[row][col] != -1 else next
                if move_ptDict[des] == -1:
                    move_ptDict[des] = move_ptDict[cur] + 1
                    queue.append(des)
                if move_ptDict[self.terminal_num] != -1:
                    return move_ptDict[self.terminal_num]
        return -1
                    
    def num2position(self,num):
        if num >= self.terminal_num:
            return 0,0
        row = self.len-1-(num-1)//self.len
        col = (num-1)%self.len if (self.len%2 == 0 and row%2 == 1) or \
            (self.len%2 == 1 and row%2 == 0) else (self.len - num%self.len)%self.len
        return row,col

if __name__ == '__main__':
    a = Solution()
    print(a.snakesAndLadders([[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]))
    print(a.snakesAndLadders([[-1,-1],[-1,3]]))
    print(a.snakesAndLadders([[-1,-1,-1,-1],[-1,-1,-1,9],[-1,-1,-1,-1],[-1,-1,11,-1]]))