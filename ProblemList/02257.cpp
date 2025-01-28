#include <vector>
using namespace std;
class Solution {
private:
    void dfs(int row, int col, int drow, int dcol, vector<vector<int>>& grid){
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() 
        || grid[row][col] == 2) return;
        grid[row][col] = 0;
        dfs(row+drow, col+dcol, drow, dcol, grid);
        return;
    }
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n,1));
        for(auto& w: walls){
            grid[w[0]][w[1]] = 2;
        }
        for(auto& g: guards){
            grid[g[0]][g[1]] = 2;
        }
        vector<int> drow = {1,0,-1,0};
        vector<int> dcol = {0,1,0,-1};
        for(auto& g: guards){
            for(int i=0; i<4; i++){
                dfs(g[0]+drow[i],g[1]+dcol[i],drow[i],dcol[i],grid);
            }
            
        }
        
        int sum = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){ 
                sum += grid[i][j] == 1 ? 1 : 0;
            }
        }
        return sum;
    }
};