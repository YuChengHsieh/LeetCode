#include <vector>
using namespace std;

// 2d dp
class Solution {
    public:
        int lenLongestFibSubseq(vector<int>& arr) {
            int n = arr.size();
            vector<vector<int>> dp(n, vector<int>(n,0));
            unordered_map<int,int> mp;
            int max_val = 0;
    
            for(int i=0; i<n; i++){
                for(int j=i+1; j<n; j++){
                    if(mp.count(arr[j]-arr[i])){
                        dp[i][j] = dp[mp[arr[j]-arr[i]]][i] + 1;
                    }
                    max_val = max(max_val,dp[i][j]);
                }
                mp[arr[i]] = i;
            }
            return max_val == 0 ? 0 : max_val+2;
        }
    };