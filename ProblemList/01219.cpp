#include <vector>
using namespace std;
class Solution {
private:
    int dfs(int r, int c, vector<vector<int>>& grid){
        if(r >= grid.size() || r < 0 || c >= grid[0].size() || c < 0 || grid[r][c] == 0) return 0;
        int val = grid[r][c], ans = 0;
        grid[r][c] = 0;
        ans = max(ans,dfs(r+1,c,grid));
        ans = max(ans,dfs(r-1,c,grid));
        ans = max(ans,dfs(r,c+1,grid));
        ans = max(ans,dfs(r,c-1,grid));
        grid[r][c] = val;
        return ans+grid[r][c];
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        // dfs
        int ans = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] != 0){
                    vector<vector<int>> tmp_grid = grid;
                    ans = max(ans,dfs(i,j,tmp_grid));
                }
            }
        }
        return ans;
    }
};