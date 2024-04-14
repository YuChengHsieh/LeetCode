#include <string>
using namespace std;
class Solution {
public:
    int minSwaps(string s) {
        int invalid_cnt = 0, left_cnt = 0, right_cnt = 0;
        for(auto& ch: s){
            if(ch == '[') left_cnt += 1;
            else if(ch == ']'){
                if(right_cnt >= left_cnt) invalid_cnt += 1;
                else left_cnt -= 1;
            } 
        }
        return (invalid_cnt+1)/2;
    }
};