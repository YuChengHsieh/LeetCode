#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<unordered_map<int,int>> dp(k+1);
        vector<int> res(k+1,0);

        for(auto& num: nums){
            for(int i=k; i>=0; i--){
                dp[i][num] = max(dp[i][num]+1, i > 0 ? res[i-1]+1 : 0);
                res[i] = max(res[i], dp[i][num]);
            }
        }
        return res[k];
    }
};