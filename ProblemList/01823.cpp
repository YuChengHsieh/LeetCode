#include <vector>
using namespace std;
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> nums(n,0);
        for(int i=0; i<n; i++){
            nums[i] = i+1;
        }
        
        int idx = 0;
        while(nums.size() > 1){
            int next_idx = (idx+k-1)%nums.size();
            nums.erase(nums.begin()+next_idx);
            idx = next_idx;
        }
        return nums[0];
    }
};