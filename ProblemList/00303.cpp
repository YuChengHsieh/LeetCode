#include<vector>
using namespace std;
class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix = vector<int>(n+1,0);

        for(int i=1; i<=n; i++){
            prefix[i] = prefix[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right+1] - prefix[left];
    }
};