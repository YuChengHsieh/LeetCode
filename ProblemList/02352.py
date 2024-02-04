from collections import defaultdict
class Solution:
    def equalPairs(self, grid: list[list[int]]) -> int:
        num_row = len(grid); num_col = len(grid[0])
        row_dict = defaultdict(int)
        col_dict = defaultdict(int)
        for i in range(num_row):
            key = []
            for j in range(num_col):
                key.append(grid[i][j])
            row_dict[tuple(key)] += 1
        
        for i in range(num_col):
            key = []
            for j in range(num_row):
                key.append(grid[j][i])
            col_dict[tuple(key)] += 1
        
        ans = 0
        for key,val in row_dict.items():
            if key in col_dict:
                ans += val*col_dict[key] 
        return ans