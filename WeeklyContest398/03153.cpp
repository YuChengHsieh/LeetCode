#include <vector>
using namespace std;
class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int val = nums[0], digit = 0;
        while(val > 0){
            val /= 10;
            digit += 1;
        }
        vector<vector<int>> digits_arr(digit, vector<int> (10,0));

        for(auto num: nums){
            int cur_digit = 0;
            while(num > 0){
                digits_arr[cur_digit][num%10] += 1;
                cur_digit ++;
                num /= 10;
            }
        }
        
        long long ans = 0;
        for(int i=0; i<digit; i++){
            for(int j=0; j<10; j++){
                for(int k=j+1; k<10; k++){
                    if(digits_arr[i][j] != 0 && digits_arr[i][k] != 0) ans += digits_arr[i][j]*digits_arr[i][k];
                }
            }
        }
        return ans;
        
    }
};