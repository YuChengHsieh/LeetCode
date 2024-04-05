#include <vector>
using namespace std;
class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int ans = 0;
        for(auto& num: nums){
            int digit = 0, max_val = 0;
            while(num != 0){
                max_val = max(max_val, num%10);
                digit += 1;
                num /= 10;
            }
            
            for(int i=0; i<digit; i++){
                ans += max_val*pow(10,i);
            }
        }
        return ans;
    }
};