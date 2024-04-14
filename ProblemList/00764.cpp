#include <vector>
using namespace std;
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> matrix(n, vector<int>(n,1));
        vector<vector<vector<int>>> dp(n+2,vector<vector<int>>(n+2, vector<int>(4,0)));
        for(auto& mine: mines) matrix[mine[0]][mine[1]] = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 1){
                    dp[i+1][j+1][0] = dp[i][j+1][0]+1;
                    dp[i+1][j+1][1] = dp[i+1][j][1]+1;
                }else{
                    dp[i+1][j+1][0] = 0;
                    dp[i+1][j+1][1] = 0;
                }
                
            }
        }

        for(int i=n-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(matrix[i][j] == 1){
                    dp[i+1][j+1][2] = dp[i+1][j+2][2]+1;
                    dp[i+1][j+1][3] = dp[i+2][j+1][3]+1;
                }else{
                    dp[i+1][j+1][2] = 0;
                    dp[i+1][j+1][3] = 0;
                }
                
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int tmp = INT_MAX;
                for(int k=0; k<4; k++){
                    tmp = min(tmp,dp[i+1][j+1][k]);
                }
                ans = max(tmp, ans);
            }
        }
        return ans;
    }
};