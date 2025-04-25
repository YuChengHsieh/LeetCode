#include <vector>
using namespace std;
class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int pos_cnt = 0, neg_cnt = 0;
            for(auto& num: nums){
                if(num > 0) pos_cnt++;
                else if(num < 0) neg_cnt++;
            }
            return max(pos_cnt,neg_cnt);
        }
    };