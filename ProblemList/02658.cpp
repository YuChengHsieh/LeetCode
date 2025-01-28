#include <vector>
using namespace std;
class Solution {
    int num = 0;
    void dfs(int r, int c, vector<vector<int>>& grid){
        if(r < 0 || r == grid.size() || c < 0 || 
        c == grid[0].size() || grid[r][c] == 0 ) return;
        num += grid[r][c];
        grid[r][c] = 0;
        dfs(r+1,c,grid);
        dfs(r,c+1,grid);
        dfs(r-1,c,grid);
        dfs(r,c-1,grid);
        return;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]){
                    dfs(i,j,grid);
                    ans = max(ans, num);
                    num = 0;
                }
            }
        }
        return ans;
    }
};