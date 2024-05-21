#include <vector>
using namespace std;
class Solution {
private:
    bool count = true;
    void dfs(int row, int col, vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        if(row < 0 || col < 0 || row >= grid1.size() || col >= grid1[0].size() || grid2[row][col] == 0) return;
        if(grid2[row][col] == 1 && grid1[row][col] == 0) count = false;
        grid2[row][col] = 0;
        dfs(row+1, col, grid1, grid2);
        dfs(row-1, col, grid1, grid2);
        dfs(row, col+1, grid1, grid2);
        dfs(row, col-1, grid1, grid2);
        return;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans = 0;
        for(int i=0; i<grid1.size(); i++){
            for(int j=0; j<grid1[0].size(); j++){
                if(grid2[i][j] == 1){
                    dfs(i,j,grid1,grid2);
                    if(count) ans += 1;
                    count = true;
                }
            }
        }
        return ans;
    }
};