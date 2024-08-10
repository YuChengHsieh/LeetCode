#include <math.h>
using namespace std;
class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int val1=sqrt(c); val1 >= 0; val1--){
            int rest = c - val1*val1;
            if(rest > val1*val1) break;
            int val2 = sqrt(rest);
            if(val2*val2 == rest) return true;
        }
        return false;
    }
};