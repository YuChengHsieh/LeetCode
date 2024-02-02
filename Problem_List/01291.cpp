#include <vector>
using namespace std;
class Solution {
private:
    int count_digit(int val){
        int cnt = 0;
        while (val != 0){
            val /= 10;
            cnt += 1;
        }
        return cnt;
    }
    int construct_num(int num, bool mode){
        int digit = 1, ret_val = 0;
        for(int i=num; i>0; i--){
            ret_val += mode ? digit : i*digit;
            if(i == 1) break;
            digit *= 10;
        }
        return ret_val;
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        int low_digits = count_digit(low);
        int high_digits = count_digit(high);
        vector<int> ans;
        for(int i=low_digits; i<=high_digits; i++){
            int num = construct_num(i,false);
            int adder = construct_num(i,true);
            for(int j=0; j<=9-i; j++){
                // cout << i << ' ' << num << ' ' << adder << endl;
                if(num >= low && num <= high) ans.push_back(num);
                num += adder;
            }
        }
        return ans;
    }
};