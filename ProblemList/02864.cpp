#include <string>
using namespace std;
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int one_cnt = 0;
        for(auto& ch: s){
            if(ch == '1') one_cnt += 1;
        }

        string ans;
        for(int i=one_cnt; i>1; i--){
            ans += '1';
        }
        for(int i=0; i<s.size()-one_cnt; i++){
            ans += '0';
        }
        if(one_cnt >= 1) ans += '1';
        return ans;
    }
};