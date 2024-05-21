#include <vector>
using namespace std;
class Solution {
private:
    int cur_area = 0;
    void dfs(int row, int col, vector<vector<int>>& grid){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == 0) return;
        
        grid[row][col] = 0;
        cur_area += 1;
        dfs(row-1,col, grid);
        dfs(row+1,col, grid);
        dfs(row,col-1, grid);
        dfs(row,col+1, grid);
        return;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    dfs(i,j,grid);
                    max_area = max(max_area,cur_area);
                    cur_area = 0;
                } 
            }
        }
        return max_area;
    }
};