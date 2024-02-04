class Solution:
    def spiralOrder(self, matrix: list[list[int]]) -> list[int]:
        matrix = matrix
        direction = [[0,1],[1,0],[0,-1],[-1,0]] # left, down, right, up
        ans = []
        # left, down, right, up barrier, why up == not 0 ==> can not return (0,0)
        left, down, right, up = len(matrix[0])-1,len(matrix)-1,0,1 
        cur_pt = [0,0]
        dir_idx = 0
        while cur_pt[1] <= left and cur_pt[0] <= down  and \
            cur_pt[1] >= right and cur_pt[0] >= up-1:
            ans.append(matrix[cur_pt[0]][cur_pt[1]])
            if dir_idx == 0 and cur_pt[1] == left:# exceed left
                dir_idx += 1
            elif dir_idx == 1 and cur_pt[0] == down:# exceed down
                dir_idx += 1
            elif dir_idx == 2 and cur_pt[1] == right:# exceed right
                dir_idx += 1
            if dir_idx == 3 and cur_pt[0] == up:# exceed up (why if not elif ==> case [[1,2],[3,4]] go up ==> exceed)
                dir_idx = 0
                left -= 1; right += 1; down -= 1; up += 1

            cur_pt[0] += direction[dir_idx][0]
            cur_pt[1] += direction[dir_idx][1]
        return ans

if __name__ == '__main__':
    a = Solution()
    print(a.spiralOrder([[1,2,3,4],[5,6,7,8]]))
    print(a.spiralOrder([[1],[2],[3]]))
    print(a.spiralOrder([[1,2,3],[4,5,6],[7,8,9]]))
    print(a.spiralOrder([[1,2,3,4],[5,6,7,8],[9,10,11,12]]))