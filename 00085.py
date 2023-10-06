class Solution:
    def maximalRectangle(self, matrix: list[list[str]]) -> int:
        row_len = len(matrix[0])
        max_area = 0
        
        left = [0 for i in range(row_len)]
        right = [len(matrix[0]) for i in range(row_len)]
        height = [0 for i in range(row_len)]
        
        for row in matrix:
            
            # count height of position i
            for i,col in enumerate(row):
                height[i] = height[i]+1 if col == '1' else 0

            # count left boundary of height[i]
            cur_left = 0
            for i,col in enumerate(row):
                if col == '1':
                    left[i] = max(left[i],cur_left)
                else:
                    left[i] = 0
                    cur_left = i+1

            # count right boundary of height[i]
            cur_right = row_len-1
            for i,col in reversed(list(enumerate(row))):
                if col == '1':
                    right[i] = min(right[i],cur_right)
                else:
                    right[i] = row_len
                    cur_right = i-1
            
            # count max area
            for i in range(row_len):
                area = ((right[i]+1)- left[i])*height[i]
                max_area = max(max_area,area) 
            
        return max_area

if __name__ == '__main__':
    a = Solution()
    print(a.maximalRectangle([["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]))