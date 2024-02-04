class Solution:
    def numSubmatrixSumTarget(self, matrix: list[list[int]], target: int) -> int:
        m = len(matrix); n = len(matrix[0])
        
        for i in range(m):
            for j in range(1,n):
                matrix[i][j] += matrix[i][j-1]

        cnt = 0
        for c1 in range(n):
            for c2 in range(c1,n):
                prefix_sum_map = {0:1}
                sum_ = 0
                for row in range(m):
                    sum_ += matrix[row][c2] - (matrix[row][c1-1] if c1 > 0 else 0)
                    cnt += prefix_sum_map.get(sum_-target,0)
                    prefix_sum_map[sum_] = prefix_sum_map.get(sum_,0)+1
                    # print(row,c1,c2,sum_,cnt,prefix_sum_map)
        return cnt