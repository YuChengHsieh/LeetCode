#include <vector>
using namespace std;
class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int rows_cnt = 0, cols_cnt = 0, m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++){
            int right = n-1;
            for(int j=0; j<n/2; j++){
                if(grid[i][j] != grid[i][right-j]) rows_cnt += 1;
            }
        }

        for(int i=0; i<n; i++){
            int right = m-1;
            for(int j=0; j<m/2; j++){
                if(grid[j][i] != grid[right-j][i]) cols_cnt += 1;
            }
        }

        return min(rows_cnt,cols_cnt);
    }
};