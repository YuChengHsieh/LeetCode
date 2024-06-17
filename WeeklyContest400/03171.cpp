#include <vector>
using namespace std;
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        // sliding window
        vector<int> cnt(31,0);
        int left = 0, ans = INT_MAX;                
        for(int right=0; right<nums.size(); right++){
            int idx = 0, num = nums[right];
            while(num != 0){
                cnt[idx++] += (num%2 == 1);
                num /= 2;
            }

            int cur_num = 0;
            for(int i=0; i<31; i++){
                if(cnt[i] == right-left+1) cur_num += (1 << i);
            }

            ans = min(ans, abs(cur_num - k));
            while(left < right && cur_num < k){
                int sub_num = nums[left], idx = 0;
                while(sub_num != 0){
                    cnt[idx++] -= (sub_num%2 == 1);
                    sub_num /= 2;
                }
                
                left ++;
                cur_num = 0;
                for(int i=0; i<31; i++){
                    if(cnt[i] == right-left+1) cur_num += (1 << i);
                }
                ans = min(ans, abs(cur_num - k));
            }
        }
        return ans;
    }
};