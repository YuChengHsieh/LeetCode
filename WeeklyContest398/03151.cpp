#include <vector>
using namespace std;
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int prev = nums[0];
        for(int i=1; i<nums.size(); i++){
            if((prev%2 == 0 && nums[i]%2 == 0) || (prev%2 == 1 && nums[i]%2 == 1) ) return false;
            prev = nums[i];
        }
        return true;
    }
};