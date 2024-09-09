#include <vector>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> cnts(3,0);
        for(auto& b: bills){
            if(b == 5) cnts[0] ++;
            else if(b == 10){
                if(cnts[0] == 0) return false;
                cnts[0] --;
                cnts[1] ++;
            }else{
                if(cnts[1] > 0 && cnts[0] > 0){
                    cnts[1] --;
                    cnts[0] --;
                }else if(cnts[0] >= 3){
                    cnts[0] -= 3;
                }else return false;
            }
        }
        return true;
    }
};