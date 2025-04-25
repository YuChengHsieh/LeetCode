#include <vector>
using namespace std;
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int max_sum = 0, cur_sum = 0, prev = -1;
        for(auto& num: nums){
            if(num > prev) cur_sum +=  num;
            else cur_sum = num;
            max_sum = max(max_sum, cur_sum);
            prev = num;
        }
        return max_sum;
    }
};