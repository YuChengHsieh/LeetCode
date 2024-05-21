#include <vector>
using namespace std;
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        // find one of the grid
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    if(i-1 < 0 || grid[i-1][j] == 0) ans += 1;
                    if(i+1 >= m || grid[i+1][j] == 0) ans += 1;
                    if(j-1 < 0 || grid[i][j-1] == 0) ans += 1;
                    if(j+1 >= n || grid[i][j+1] == 0) ans += 1;
                }
            }
        }
        return ans;
    }
};