#include <vector>
using namespace std;
class Solution {
private:
    int dp(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& mem){
        if(mem[r][c] != -1) return mem[r][c];
        int ans = 0;
        
        if(r+1 < grid.size()) ans = max(ans, max(0, dp(r+1,c,grid,mem)+grid[r+1][c] - grid[r][c]));
        if(c+1 < grid[0].size()) ans = max(ans, max(0, dp(r,c+1,grid,mem)+grid[r][c+1] - grid[r][c]));
        return mem[r][c] = ans;

    }
public:
    int maxScore(vector<vector<int>>& grid) {
        vector<vector<int>> mem(grid.size(), vector<int>(grid[0].size(),-1));
        
        dp(0,0,grid,mem);
        int ans = INT_MIN;
        for(int i=grid.size()-1; i>=0; i--){
            for(int j=grid[0].size()-1; j>=0; j--){
                ans = max(ans, mem[i][j]);
            }
        }
        
        if(ans == 0){
            ans = INT_MIN;
            for(int i=0; i<grid.size(); i++){
                for(int j=0; j<grid[0].size(); j++){
                    if(i+1 != grid.size())ans = max(ans,grid[i+1][j]-grid[i][j]);
                    if(j+1 != grid[0].size())ans = max(ans,grid[i][j+1]-grid[i][j]);
                }
            }
        }
        
        return ans;
    }
};