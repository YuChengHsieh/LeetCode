#include <vector>
using namespace std;
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size()+1,0);
        for(int i=1; i<=arr.size(); i++){
            int max_val = 0;
            for(int j=i-1; j>=max(i-k,0); j--){
                max_val = max(max_val,arr[j]);
                dp[i] = max(dp[i],dp[j]+max_val*(i-j));
            }
        }
        return dp[dp.size()-1];
    }
};