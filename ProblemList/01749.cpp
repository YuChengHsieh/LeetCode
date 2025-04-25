#include <vector>
using namespace std;

class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int max_sum = 0, cur_maxsum = 0, min_sum = 0, cur_minsum = 0;
            for(auto& num: nums){
                cur_maxsum = cur_maxsum < 0 ? num : cur_maxsum + num;
                max_sum = max(max_sum, cur_maxsum);
                cur_minsum = cur_minsum > 0 ? num : cur_minsum + num;
                min_sum = min(min_sum, cur_minsum);
            }
    
            return max(max_sum,-min_sum);
        }
    };