#include <vector>
using namespace std;
class Solution {
private:
    int inf = 1e9;
    int dp(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& mem){
        if(mem[row][col] != -1) return mem[row][col];
        int ans = 0;
        if(row - 1 >= 0 && col+1 < grid[0].size() && grid[row-1][col+1] > grid[row][col]) ans = max(ans, dp(row-1,col+1,grid,mem)+1);
        if(col+1 < grid[0].size() && grid[row][col+1] > grid[row][col]) ans = max(ans, dp(row,col+1,grid,mem)+1);
        if(row + 1 < grid.size() && col+1 < grid[0].size() && grid[row+1][col+1] > grid[row][col]) ans = max(ans, dp(row+1,col+1,grid,mem)+1);
        return mem[row][col] = ans;
    }
public:
    int maxMoves(vector<vector<int>>& grid) {
        vector<vector<int>> mem(grid.size(), vector<int>(grid[0].size(),-1));
        int ans = 0;
        for(int i=0; i<grid.size(); i++){
            ans = max(ans, dp(i,0,grid,mem));
        }
        return ans;
    }
};