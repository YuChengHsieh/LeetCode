#include <set>
using namespace std;
class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        set<int> dict;
        for(int i=0; i<nums.size()-1; i++){
            if(dict.count(nums[i] + nums[i+1])) return true;
            dict.insert(nums[i] + nums[i+1]);
        }
        return false;
    }
};