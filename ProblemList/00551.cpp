#include <string>
using namespace std;
class Solution {
public:
    bool checkRecord(string s) {
        int late_cnt = 0;
        int abs_cnt = 0;
        for(auto& ch: s){
            if(ch == 'L'){
                late_cnt ++;
                if(late_cnt == 3) return false;
            }else{
                late_cnt = 0;
                if(ch == 'A'){
                    abs_cnt ++;
                    if(abs_cnt == 2) return false;
                }
            }
        }
        return true;
    }
};