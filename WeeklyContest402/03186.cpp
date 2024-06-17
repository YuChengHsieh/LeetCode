#include <vector>
#include <map>
#include <set>
using namespace std;
class Solution {
public:
    long long maximumTotalDamage(vector<int>& pow) {
        map<int,long long> mp;
        map<int, long long> dp;
        long long max_val = 0;
        for(auto& p: pow){
            mp[p] ++;
        }
        
        set<int> pow_set(pow.begin(), pow.end());
        vector<int> power(pow_set.begin(), pow_set.end());
        sort(power.begin(), power.end());
        
        for(long long p: power){
            auto it = dp.upper_bound(p-3);
            long long first_val = dp.count(p-1) ? dp[p-1] : 0, second_val =  dp.count(p-2) ? dp[p-2] : 0;
            if(it == dp.begin()){
                dp[p] = max(max(first_val,second_val),(long long)(mp[p]*p));
            }else{
                -- it;
                dp[p] = max(max(first_val,second_val),(long long)(it -> second + mp[p]*p));
            }
            max_val = max(max_val, dp[p]);
        }
        return max_val;
    }
};