#include <vector>
using namespace std;
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n,0), suffix(n,0);
        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        for(int i=n-2; i>=0; i--){
            suffix[i] = suffix[i+1] + nums[i];
        }
        int ans = 0;
        for(int i=0; i<n-1; i++){
            if(prefix[i] >= suffix[i+1]) ans ++;
        }
        return ans;
    }
};