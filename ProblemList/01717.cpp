#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int a_cnt = 0, b_cnt = 0, ans = 0;
        bool x_major = true;
        if(y > x) x_major = false;
        for(auto&ch: s){
            if(x_major){
                if(ch == 'b'){
                    if(a_cnt > 0){
                        a_cnt -= 1;
                        ans += x;
                    }else b_cnt += 1;
                }else if(ch == 'a'){
                    a_cnt += 1;
                }else{
                    ans += min(a_cnt,b_cnt)*y;
                    a_cnt = 0;
                    b_cnt = 0;
                }
            }else{
                if(ch == 'a'){
                    if(b_cnt > 0){
                        b_cnt -= 1;
                        ans += y;
                    }else a_cnt += 1;
                }else if(ch == 'b'){
                    b_cnt += 1;
                }else{
                    ans += min(a_cnt,b_cnt)*x;
                    a_cnt = 0;
                    b_cnt = 0;
                }
            }
        }
        return ans + (x_major ? min(a_cnt,b_cnt)*y : min(a_cnt,b_cnt)*x);
    }
};