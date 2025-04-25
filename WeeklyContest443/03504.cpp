#include <string>
#include <vector>
using namespace std;
class Solution {
    public:
        int longestPalindrome(string s, string t) {
            int m = s.size(), n = t.size();
            int ans = 0;
            vector<vector<bool>> dpS(m, vector<bool>(m, false));
            vector<int> spal(m,0);
            for(int i=m-1; i>=0; i--){
                for(int j=i; j<m; j++){
                    if(s[i] == s[j] && ( j-i < 2 || dpS[i+1][j-1])){
                        dpS[i][j] = true;
                        spal[i] = max(spal[i],j-i+1);
                        ans = max(ans,spal[i]);
                    }
                }
            }
    
            // reverse t
            vector<vector<bool>> dpT(n, vector<bool>(n, false));
            vector<int> tpal(n,0);
            for(int i=0; i<n; i++){
                for(int j=i; j>=0; j--){
                    if(t[i] == t[j] && ( i-j < 2 || dpT[i-1][j+1])){
                        dpT[i][j] = true;
                        tpal[i] = max(tpal[i],i-j+1);
                        ans = max(ans,tpal[i]);
                    }
                }
            }
    
            vector<vector<int>> dp(m, vector<int>(n, 0));
            for(int i=0; i<m; i++){
                for(int j=n-1; j>=0; j--){
                    if(s[i] == t[j]){
                        dp[i][j] =  (i-1 >=0 && j+1 < n) ? 1 + dp[i-1][j+1] : 1;
    
                    }
                    if(dp[i][j]){
                        int extra = max(i+1 < m ? spal[i+1] : 0 , j-1 >= 0 ? tpal[j-1] : 0);
                        ans = max(ans, 2*dp[i][j] + extra);
                    }
                }
            }
            return ans;
        }
    };