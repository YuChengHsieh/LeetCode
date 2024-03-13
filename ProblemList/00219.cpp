#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int n = nums.size();
        for(int i=0; i<=min(n-1,k); i++){
            map[nums[i]] += 1;
            if(map[nums[i]] >= 2) return true;
        }

        if(k >= n) return false;
        int left = 0;
        for(int i=min(n-1,k)+1; i<=max(n-1,k); i++){
            map[nums[left++]] -= 1;
            map[nums[i]] += 1;
            if(map[nums[i]] >= 2) return true;
        }
        return false;
    }
};