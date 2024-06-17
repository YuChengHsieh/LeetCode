#include <vector>
using namespace std;
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int lower_num = 0, ans = 0;
        for(auto& num: nums){
            if(lower_num > num){
                ans += lower_num - num;
                lower_num += 1;
            }
            else lower_num = num+1;
        }
        return ans;
    }
};