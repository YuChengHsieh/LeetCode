#include <vector>
#include <map>
using namespace std;
class Solution {
    public:
        long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
            int sum = 0;
            map<int,int> mp;
            long long ans = 0;
            mp[0] = 1;
            for(int i=0; i<nums.size(); i++){
                sum += nums[i]%modulo == k;
                ans += mp[(sum-k+modulo)%modulo];
                mp[sum%modulo] ++;
            }
            return ans;
        }
    };