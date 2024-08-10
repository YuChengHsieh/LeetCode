#include <vector>
using namespace std;
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int max_row = 0, min_row = m, max_col = 0, min_col = n;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                        max_row = max(max_row,i);
                        min_row = min(min_row,i);
                        max_col = max(max_col,j);
                        min_col = min(min_col,j);
                }
            }
        }
        return (max_row-min_row+1)*(max_col-min_col+1);
    }
};