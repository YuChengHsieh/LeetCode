#include <vector>
using namespace std;
class Solution {
private:
    int dp(int cur, int prev, vector<vector<int>>& grid, vector<vector<int>>& mem){
        if(cur == grid.size()) return 0;
        if(mem[cur][prev] != -1) return mem[cur][prev];
        int ans = INT_MAX;
        
        for(int i=0; i<grid.size(); i++){
            if(i != prev) ans = min(ans, dp(cur+1,i,grid,mem)+grid[cur][i]);
        }

        return mem[cur][prev] = ans;
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 1) return grid[0][0];
        vector<vector<int>> mem(n, vector<int>(n+1,-1));
        return dp(0,n,grid,mem);
    }
};