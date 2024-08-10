#include <vector>
#include <map>

// Brutal force
using namespace std;
class Solution {
    int minimumArea(int row1, int row2, int col1, int col2, vector<vector<int>>& grid, map<vector<int>,int>& mem){
        if(mem.count({row1,row2,col1,col2})) return mem[{row1,row2,col1,col2}];
        int max_row = row1, min_row = row2, max_col = col1, min_col = col2;
        for(int i=row1; i<row2; i++){
            for(int j=col1; j<col2; j++){
                if(grid[i][j] == 1){
                        max_row = max(max_row,i);
                        min_row = min(min_row,i);
                        max_col = max(max_col,j);
                        min_col = min(min_col,j);
                }
            }
        }
        return mem[{row1,row2,col1,col2}] = max(0,(max_row-min_row+1)*(max_col-min_col+1));
    }
public:
    int minimumSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = m*n;
        map<vector<int>,int> mem;
        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                ans = min(ans,minimumArea(0,row,0,n,grid,mem) + minimumArea(row,m,0,col,grid,mem) + minimumArea(row,m,col,n,grid,mem));
                ans = min(ans,minimumArea(0,row,0,col,grid,mem) + minimumArea(0,row,col,n,grid,mem) + minimumArea(row,m,0,n,grid,mem));
                ans = min(ans,minimumArea(0,row,0,col,grid,mem) + minimumArea(row,m,0,col,grid,mem) + minimumArea(0,m,col,n,grid,mem));
                ans = min(ans,minimumArea(0,m,0,col,grid,mem) + minimumArea(0,row,col,n,grid,mem) + minimumArea(row,m,col,n,grid,mem));
            }
        }

        for(int row1 = 0; row1 < m ; row1 ++){
            for(int row2 = row1+1; row2 < m; row2 ++){
                ans = min(ans, minimumArea(0,row1,0,n,grid,mem) + minimumArea(row1,row2,0,n,grid,mem) + minimumArea(row2,m,0,n,grid,mem));
            }    
        }

        for(int col1 = 0; col1 < n ; col1 ++){
            for(int col2 = col1+1; col2 < n; col2 ++){
                ans = min(ans, minimumArea(0,m,0,col1,grid,mem) + minimumArea(0,m,col1,col2,grid,mem) + minimumArea(0,m,col2,n,grid,mem));
            }    
        }

        return ans;
    }
};