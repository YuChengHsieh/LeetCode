# backtracking
class Solution:
    def exist(self, board: list[list[str]], word: str) -> bool:
        visit = []
        row_len = len(board)
        col_len = len(board[0])
        word_len = len(word)
        for _ in range(row_len):
            visit.append([False for _ in range(col_len)])
        
        def rec(pos,idx):
            if idx == word_len:
                return True
            way_to_go = []
            if pos[0]-1 >= 0 and not visit[pos[0]-1][pos[1]]:
                way_to_go.append([pos[0]-1,pos[1]])
            if pos[0]+1 < row_len and not visit[pos[0]+1][pos[1]]:
                way_to_go.append([pos[0]+1,pos[1]])
            if pos[1]-1 >= 0 and not visit[pos[0]][pos[1]-1]:
                way_to_go.append([pos[0],pos[1]-1])
            if pos[1]+1 < col_len and not visit[pos[0]][pos[1]+1]:
                way_to_go.append([pos[0],pos[1]+1])

            for row,col in way_to_go:
                if board[row][col] == word[idx]:
                    visit[row][col] = True
                    find = rec([row,col],idx+1)
                    if find:
                        return True
                    visit[row][col] = False
            return False
        
        # check if character of word in board, if not return false
        word_set = set(word)
        board_str = ''

        for i in range(row_len):
            for j in range(col_len):
                board_str += board[i][j]
        board_set = set(board_str)
        
        for char in word_set:
            if char not in board_set:
                return False

        # find first element 
        for i in range(row_len):
            for j in range(col_len):
                if board[i][j] == word[0]:
                    visit[i][j] = True
                    find = rec([i,j],1)
                    visit[i][j] = False
                    if find:
                        return True
        return False

if __name__ == '__main__':
    a = Solution()
    print(a.exist([["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]],"ABCCED"))
    print(a.exist([["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]],"SEE"))
    print(a.exist([["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]],"ABCB"))
    print(a.exist([['a','a']],"aaa"))
    print(a.exist([["a","b"],["c","d"]],"bacd"))
        
        