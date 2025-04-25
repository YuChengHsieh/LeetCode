#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]-i] += 1;
        }
        long long ans = 0;
        for(int i=0; i<nums.size(); i++){
            ans += nums.size() - mp[nums[i]-i];
        }
        return ans/2;
    }
};