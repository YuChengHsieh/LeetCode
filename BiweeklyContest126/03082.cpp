#include<vector>
#include<map>
using namespace std;

class Solution {
private:
    int mod = pow(10,9)+7;
    long long ans = 0;
    long long rec(long long idx, long long cnt, long long sum, int k, vector<int>& nums, map<vector<long long>,long long>& mem){
        if(sum == k){
            long long ret_val = 1;
            for(int i=0; i<(int)nums.size()-cnt; i++){
                ret_val = 2*ret_val;
                ret_val %= mod;
            }
            return ret_val;
        }
        else if(sum > k || idx >= nums.size()) return 0;
        if(mem.count({idx,cnt,sum})) return mem[{idx,cnt,sum}];
        
        long long ans = 0;
        ans += rec(idx+1, cnt+1, sum+nums[idx], k, nums, mem)%mod;
        ans %= mod;
        ans += rec(idx+1, cnt, sum, k, nums, mem)%mod;
        ans %= mod;
        return mem[{idx,cnt,sum}] = ans;
    }
public:
    int sumOfPower(vector<int>& nums, int k) {
        map<vector<long long>,long long> mem;
        return (int)(rec(0LL,0LL,0LL,k,nums, mem)%mod);
    }
};