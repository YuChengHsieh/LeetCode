#include <vector>
using namespace std;

// space complexity o(n)
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> lower, upper;
        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < pivot) lower.push_back(nums[i]);
            else if(nums[i] > pivot) upper.push_back(nums[i]);
            else cnt ++;
        }
        
        for(int i=0; i<cnt; i++){
            lower.push_back(pivot);
        }
        lower.insert(lower.end(),upper.begin(), upper.end());
        return lower;
    }
};