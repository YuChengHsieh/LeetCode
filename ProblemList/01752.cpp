#include <vector>
using namespace std;
class Solution {
public:
    bool check(vector<int>& nums) {
        int prev = nums[0];
        bool check = false;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] < prev){
                if(check) return false;
                check = true;
            }
            prev = nums[i];
        }
        return check && nums.back() > nums[0] ? false : true;
    }
};