class Solution:
    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        # BFS + memorization
        mem = {}
        direction = [(-2,-1),(-1,-2),(1,-2),(2,-1),(2,1),(1,2),(-1,2),(-2,1)]

        def rec(move,r,c):
            if r<0 or c<0 or r>=n or c>=n:
                return 0
            if move == 0:
                return 1
            key = str(move)+'.'+str(r)+'.'+str(c)
            if mem.get(key):
                return mem[key]
            prob = 0
            for drow, dcol in direction:
                tmp = 1/8*rec(move-1,r+drow,c+dcol)
                prob += tmp
                print(tmp,r+drow,c+dcol)
            mem[key] = prob
            return prob
        
        return rec(k,row,column)
