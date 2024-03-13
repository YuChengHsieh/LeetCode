#include <algorithm>
class Solution {
private:
    int cal_square(int num){
        int ans = 0;
        while(num > 0){
            ans += pow(num%10,2);
            num /= 10;
        }
        return ans;
    }
public:
    bool isHappy(int n) {
        // cycle detection
        int slow = n, fast = n;
        do{
            slow = cal_square(slow);
            fast = cal_square(cal_square(fast));
            if(slow == 1) return true;
        }while(slow != fast);
        return false;
    }
};