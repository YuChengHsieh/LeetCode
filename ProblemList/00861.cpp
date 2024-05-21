#include <vector>
using namespace std;
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        vector<bool> changed(m,false);
        for(int i=0; i<m; i++){
            if(grid[i][0] != 1) changed[i] = true;
        }
        ans += (1 << (n-1))*m;
        for(int i=1; i<n; i++){
            int one_cnts = 0;
            for(int j=0; j<m; j++){
                if((grid[j][i] == 1 && !changed[j]) || (grid[j][i] == 0 && changed[j])) one_cnts += 1;
            }
            ans += (1 << (n-1-i))*max(one_cnts,m-one_cnts);
        }
        return ans;
    }
};

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();

        ans += (1 << (n-1))*m;
        for(int i=1; i<n; i++){
            int one_cnts = 0;
            for(int j=0; j<m; j++){
                if(grid[j][i] == grid[j][0]) one_cnts += 1;
            }
            ans += (1 << (n-1-i))*max(one_cnts,m-one_cnts);
        }
        return ans;
    }
};