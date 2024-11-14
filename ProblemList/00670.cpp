#include <math.h>
using namespace std;
class Solution {
public:
    int maximumSwap(int num) {
        int cur_num = num, digits = 0;
        while(cur_num != 0){
            cur_num /= 10;
            digits ++;
        }

        int min_val = 10, pos = -1;
        bool change = false;
        cur_num = num;
        for(int i=digits-1; i>=0; i--){

            if(min_val >= cur_num/(int)pow(10,i) && !change){
                min_val = cur_num/(int)pow(10,i);
            }else{
                change = true;
                if(cur_num/(int)pow(10,i) >= min_val){
                    min_val = cur_num/(int)pow(10,i);
                    pos = i;
                }
                
            }
            cur_num -= cur_num/(int)pow(10,i)*pow(10,i);
        }

        cur_num = num;
        if(pos != -1){
            for(int i=digits-1; i>=0; i--){
                if(cur_num/(int)pow(10,i) < min_val){
                    int val = cur_num/(int)pow(10,i);
                    num -= val*pow(10,i);
                    num += min_val*pow(10,i);
                    num -= min_val*pow(10,pos);
                    num += val*pow(10,pos);
                    break;
                }
                cur_num -= cur_num/(int)pow(10,i)*pow(10,i);
            }
        }
        return num;
    }
};