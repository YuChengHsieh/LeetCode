#include <vector>
#include <string>
using namespace std; 
class Solution {
public:
    int countPairs(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            for(int j = i+1; j<nums.size(); j++){
                string a, b;
                int a_val = nums[i], b_val = nums[j];
                for(int k=0; k<7; k++){
                    a += a_val%10 + '0';
                    a_val /= 10;

                }
                // reverse(a.begin(),a.end());
                for(int k=0; k<7; k++){
                    b += b_val%10 + '0';
                    b_val /= 10;
                }
                // reverse(b.begin(),b.end());

                vector<int> diff_arr(3,0);
                bool potential_ans = false;
                for(int k=0; k<7; k++){
                    if(a[k] != b[k]){
                        if(diff_arr[0] >= 2){
                            diff_arr[0] += 1;
                            break;
                        }
                        else{
                            if(diff_arr[0] == 0){
                                diff_arr[1] = a[k];
                                diff_arr[2] = b[k];
                            }else if(a[k] == diff_arr[2] && b[k] == diff_arr[1]) potential_ans = true;
                            diff_arr[0] += 1;
                        }
                    }
                }
                if(diff_arr[0] == 0 || (diff_arr[0] == 2 && potential_ans)) ans ++;
            }
        }
        return ans;  
    }
};