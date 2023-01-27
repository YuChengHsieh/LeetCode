class Solution:
    def generateMatrix(self, n: int) -> list[list[int]]:
        dir = [[0,1],[1,0],[0,-1],[-1,0]]
        left_bound, right_bound, up_bound, down_bound = 0, n, 1, n
        start_pos = [0,0]
        ans_list = []
        cnt = 1
        dir_idx = 0
        for _ in range(n):
            ans_list.append([-1 for _ in range(n)])
        
        while start_pos[1] >= left_bound and start_pos[1] < right_bound and \
            start_pos[0] >= up_bound-1 and start_pos[0] < down_bound:
                ans_list[start_pos[0]][start_pos[1]] = cnt
                cnt += 1
                if dir_idx == 0 and start_pos[1]+dir[dir_idx][1] >= right_bound:
                    dir_idx += 1
                elif dir_idx == 1 and start_pos[0]+dir[dir_idx][0] >= down_bound:
                    dir_idx += 1
                elif dir_idx == 2 and start_pos[1]+dir[dir_idx][1] < left_bound:
                    dir_idx += 1
                if dir_idx == 3 and start_pos[0]+dir[dir_idx][0] < up_bound:
                    dir_idx = 0
                    right_bound -= 1; down_bound -= 1; left_bound += 1; up_bound += 1
                
                start_pos[0] += dir[dir_idx][0]
                start_pos[1] += dir[dir_idx][1]
        return ans_list

if __name__ == '__main__':
    a = Solution()
    print(a.generateMatrix(4))
    print(a.generateMatrix(1))            
                
                    