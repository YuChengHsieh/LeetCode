#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        map<int,int> mp;
        sort(nums.begin(), nums.end());
        int ans = -1;
        for(auto& n: nums){
            int sqrt_n = sqrt(n);
            if(mp.count(sqrt_n) && sqrt_n*sqrt_n == n){
                mp[n] = mp[sqrt_n] + 1;
                ans = max(ans, mp[n]);
            } 
            else mp[n] = 1;
        }
        return ans;
    }
};