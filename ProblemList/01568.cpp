#include <vector>
using namespace std;
class Solution {
private:
    int one_cnt = 0;
    void dfs(int row, int col, vector<vector<int>>& grid){
        if(row < 0 || col < 0 || row == grid.size() || 
            col == grid[0].size() || !grid[row][col]) return;
        one_cnt ++;
        grid[row][col] = 0;
        dfs(row-1,col, grid);
        dfs(row+1,col, grid);
        dfs(row,col-1, grid);
        dfs(row,col+1, grid);
        return;
    }
public:
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> tmp_grid = grid;
        bool connected = true;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(tmp_grid[i][j]){
                    if(!connected) return 0;
                    dfs(i,j,tmp_grid);
                    connected = false;
                }
            }
        }
        // no 1
        if(connected) return 0;
        if(one_cnt < 2) return one_cnt;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]){
                    grid[i][j] = 0;
                    vector<vector<int>> tmp_grid = grid;
                    bool connected = true;
                    for(int k=0; k<m; k++){
                        for(int l=0; l<n; l++){
                            if(tmp_grid[k][l]){
                                // cout << i << ' ' << j << ' ' << k << ' ' << l << endl;
                                if(!connected) return 1;
                                dfs(k,l,tmp_grid);
                                connected = false;
                            }
                        }
                    }
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};