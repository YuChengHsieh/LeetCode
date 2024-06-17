#include <string>
using namespace std;
class Solution {
public:
    int numSteps(string s) {
        int cnt = 0;
        while(s.size() > 1){
            int idx = s.size()-1;
            if(s[idx] == '1'){
                while(idx >= 0 && s[idx] == '1') s[idx--] = '0';
                if(idx == -1) s = '1' + s;
                else s[idx] = '1';
            }else s.pop_back();
            cnt += 1;
        }
        return cnt;
    }
};