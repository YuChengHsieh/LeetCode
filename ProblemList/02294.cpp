#include <vector>
using namespace std;
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int cnt = 1, prev = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i] - prev > k){
                cnt ++;
                prev = nums[i];
            }
        }
        return cnt;
    }
};