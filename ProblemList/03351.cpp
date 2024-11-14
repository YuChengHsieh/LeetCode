#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        int mod = 1e9 + 7;
        long long ans = 0;
        map<int, long long> mp, sum;
        for(auto& num: nums){
            long long cur_count = 1, cur_sum = num;
            int find1 = num-1;
            int find2 = num+1;

            cur_count += mp[find1] + mp[find2];
            cur_count %= mod;

            cur_sum += sum[find1]+mp[find1]*num + sum[find2]+mp[find2]*num;
            cur_sum %= mod;
            
            mp[num] += cur_count;
            mp[num] %= mod;
            sum[num] += cur_sum;
            sum[num] %= mod;

            ans += cur_sum;
            ans %= mod;
        }
        return ans;
    }
};