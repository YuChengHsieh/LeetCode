#include <vector>
#include <map>
using namespace std;
class Solution {
private:
    int mod = pow(10,9)+7;
    long long rec(int i, long long num, long long diff, int k, vector<int>& nums, vector<map<pair<long long, long long>, long long>>& mem){
        if(k == 0){
            return diff;
        } 
        if(i >= nums.size()) return 0;
        if(mem[k].count({num,diff})) return mem[k][{num,diff}];
        return mem[k][{num,diff}] = (rec(i+1,nums[i],min(diff, abs(nums[i]-num)),k-1, nums, mem)%mod + rec(i+1,num,diff,k, nums, mem)%mod)%mod;
    }
public:
    int sumOfPowers(vector<int>& nums, int k) {
        vector<map<pair<long long, long long>, long long>> mem(k+1, map<pair<long long, long long>, long long>());
        sort(nums.begin(), nums.end());
        return rec(0,(long long)INT_MAX, (long long)INT_MAX, k, nums, mem);
    }
};