class Solution:
    def winnerOfGame(self, colors: str) -> bool:
        A_cnt = B_cnt = 0
        A_cont = B_cont = 0
        for color in colors:
            if color == 'A':
               A_cont += 1
               B_cnt += max(0,B_cont-2)
               B_cont = 0
            else:
                B_cont += 1
                A_cnt += max(0,A_cont-2)
                A_cont = 0
        else:
            A_cnt += max(0,A_cont-2)
            B_cnt += max(0,B_cont-2)
        return True if A_cnt > B_cnt else False

class Solution:
    def winnerOfGame(self, colors: str) -> bool:
        Alice = Bob = 0
        for i in range(1,len(colors)-1):
            if colors[i-1] == colors[i] == colors[i+1]:
                if colors[i] == 'A': Alice += 1
                else: Bob += 1
        return True if Alice > Bob else False
