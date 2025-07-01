#include<vector>
using namespace std;
class Solution {
    public:
        int findNumbers(vector<int>& nums) {
            int ans = 0;
            for(auto num: nums){
                int digit_cnt = 0;
                while(num != 0){
                    num /= 10;
                    digit_cnt ++;
                }
                ans += (digit_cnt+1)%2;
            }
            return ans;
        }
    };