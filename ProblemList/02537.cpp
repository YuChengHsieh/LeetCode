#include <vector>
#include <map>
using namespace std;
class Solution {
    public:
        long long countGood(vector<int>& nums, int k) {
            int left = 0;
            long long ans = 0, cur = 0;
            map<int,long long> mp;
            for(int right=0; right<nums.size(); right++){
                cur += mp[nums[right]];
                mp[nums[right]] ++;
                while(cur >= k){
                    mp[nums[left]] --;
                    cur -= mp[nums[left]];
                    left ++;
                }
                ans += left;
            }
            return ans;
        }
    };