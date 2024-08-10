#include <vector>
#include <map>
#include <set>
using namespace std;
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;
        for(auto& num: nums){
            mp[num] += 1;
        }
        map<int,set<int>> rev_mp;
        for(auto& item: mp){
            rev_mp[item.second].insert(item.first);
        }

        vector<int> ans;
        for(auto& item: rev_mp){
            vector<int> nums(item.second.begin(),item.second.end());
            reverse(nums.begin(), nums.end());
            for(auto& val: nums){
                for(int i=0; i<item.first; i++){
                    ans.push_back(val);
                }
            }
        }
        return ans;
    }
};