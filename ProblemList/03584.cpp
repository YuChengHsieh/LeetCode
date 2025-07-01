#include <vector>
using namespace std;
class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        vector<int> max_arr(n,0);
        vector<int> min_arr(n,0);

        int max_val = nums[n-1], min_val = nums[n-1];
        for(int i=n-1; i>=0; i--){
            max_val = max(max_val, nums[i]);
            min_val = min(min_val, nums[i]);
            max_arr[i] = max_val;
            min_arr[i] = min_val;
        }

        long long ans = -LLONG_MAX;
        for(int i=0; i<=n-m; i++){
            ans = max(ans, max((long long)nums[i]*max_arr[i+m-1],(long long)nums[i]*min_arr[i+m-1]));
        }
        return ans;
    }
};