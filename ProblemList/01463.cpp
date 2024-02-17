#include <vector>
using namespace std;
class Solution {
private:
    int m,n;
private:
    int rec(int row, int col1, int col2, vector<vector<vector<int>>>& dp, vector<vector<int>>& grid){
        if(row >= m || col1 < 0 || col1 >=n || col2 < 0 || col2 >= n) return 0;
        if(dp[row][col1][col2] != -1) return dp[row][col1][col2];
        int ans = 0;
        for(int dc1=-1; dc1 <=1; dc1++){
            for(int dc2=-1; dc2<=1; dc2++){
                ans = max(ans,rec(row+1,col1+dc1,col2+dc2,dp,grid));
            }
        }
        ans += col1 == col2 ? grid[row][col1] : grid[row][col1]+grid[row][col2];
        dp[row][col1][col2] = ans;
        return dp[row][col1][col2];
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        // memorization
        m = grid.size(); 
        n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n,-1)));
        return rec(0,0,n-1,dp,grid);
    }
};