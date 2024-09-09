#include <vector>
using namespace std;

// recursive dp, TLE
class Solution {
long long dp(int row, int col, vector<vector<int>>& points, vector<vector<long long>>& mem){
    if(row == points.size()-1) return points[row][col];
    if(mem[row][col] != -1) return mem[row][col];
    long long ans = 0;
    for(int i=0; i<points[0].size(); i++){
        ans = max(ans, dp(row+1,i,points,mem) - abs(i-col));
    }
    return mem[row][col] = ans + points[row][col];

}
public:
    long long maxPoints(vector<vector<int>>& points) {
        long long ans = 0;
        vector<vector<long long>> mem(points.size(), vector<long long>(points[0].size(),-1));
        for(int i=0; i<points[0].size(); i++){
            ans = max(ans, dp(0,i,points,mem));
        }
        return ans;
    }
};

// iterative dp
class Solution{
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n,0));
        for(int i=0; i<n; i++){
            dp[0][i] = points[0][i];
        }

        for(int i=1; i<m; i++){
            vector<long long> left(n,0), right(n,0);
            left[0] = dp[i-1][0];
            for(int j=1; j<n; j++){
                left[j] = max(left[j-1]-1, dp[i-1][j]);
            }
            right[n-1] = dp[i-1][n-1];
            for(int j=n-2; j>=0; j--){
                right[j] = max(right[j+1]-1, dp[i-1][j]);
            }

            for(int j=0; j<n; j++){
                dp[i][j] = max(left[j],right[j]) + points[i][j];
            }
        }

        long long ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans, dp[m-1][i]);
        }
        return ans;
    }
};