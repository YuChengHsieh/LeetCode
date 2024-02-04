#include <unordered_map>
#include <vector>
using namespace std;

// dictionary
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> dict;
        int ans = 0;
        for(auto &num: nums){
            dict[num] += 1;
        }
        for(auto &item: dict){
            if(item.second == 0) continue; 
            if(dict.count(k-item.first) && dict[k-item.first] >= 0){
                // cout << item.first << ' ' << k-item.first << ' ' << dict[k-item.first] << endl;
                if(k-item.first == item.first) ans += dict[k-item.first]/2;
                else{
                    int min_val = min(dict[k-item.first],dict[item.first]);
                    ans += min_val;
                    dict[item.first] -= min_val;
                    dict[k-item.first] -= min_val;
                }
            }
        }
        return ans;
    }
};

// two pointer
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int left = 0, right = nums.size()-1, ans = 0;
        while(left < right){
            if(nums[left]+nums[right] == k){
                ans += 1;
                left += 1;
                right -= 1;
            }else if(nums[left]+nums[right] < k) left += 1;
            else right -= 1;
        }
        return ans;
    }
};