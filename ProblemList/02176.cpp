#include <vector>
using namespace std;
class Solution {
    public:
        int countPairs(vector<int>& nums, int k) {
            int ans = 0;
            for(int i=0; i<nums.size(); i++){
                for(int j=i+1; j<nums.size(); j++){
                    if(i*j%k == 0 && nums[i] == nums[j]) ans++;
                }
            }
            return ans;
        }
    };