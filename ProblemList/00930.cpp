#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> map;
        int sum = 0, ans = 0;
        for(auto & num: nums){
            map[sum] += 1;
            sum += num;
            ans += map[sum - goal];
        }

        return ans;
    }
};