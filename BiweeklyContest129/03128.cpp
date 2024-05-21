#include <vector>
using namespace std;
class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> rows(m,0);
        vector<int> cols(n,0);
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                rows[i] += grid[i][j] == 1;
                cols[j] += grid[i][j] == 1;
            }
        }
        
        
        long long ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1) ans += max(0,rows[i]-1)*max(0,cols[j]-1);
            }
        }
        return ans;
    }
};