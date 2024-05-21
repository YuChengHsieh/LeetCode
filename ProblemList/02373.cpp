#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> ans(grid.size()-2, vector<int>(grid[0].size()-2,0));
        for(int i=0; i<grid.size()-2; i++){
            for(int j=0; j<grid[0].size()-2; j++){
                int max_val = 0;
                for(int k=0; k<9; k++){
                    max_val = max(max_val,grid[i+k/3][j+k%3]);
                }
                ans[i][j] = max_val;
            }
        }
        return ans;
    }
};