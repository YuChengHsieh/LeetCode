#include <vector>
using namespace std;
class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        int mod = pow(10,9)+7;
        vector<long long> pre(n,1), nums(n,1);
        for(int i=0; i<k; i++){
            pre[0] = nums[0];
            for(int j=1; j<n; j++){
                pre[j] = (pre[j-1] + nums[j])%mod;
            }
            nums = pre;
        }
        
        return (int)pre[n-1];
    }
};