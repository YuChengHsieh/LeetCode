#include <vector>
using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        for(int i=0; i<k; i++){
            sum += nums[i];
        }
        int left = 0, max_val = sum;
        for(int i=k; i<nums.size(); i++){
            sum = sum - nums[left] + nums[i];
            max_val = max(max_val, sum);
            left += 1;
        }
        return double(max_val)/double(k);
    }
};