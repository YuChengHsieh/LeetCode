#include <vector>
using namespace std;
class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int cnt1 = 0, cnt2=0;
        int tmp_blue = blue, tmp_red = red;
        while(true){
            if(cnt1%2 == 0){
                tmp_blue -= (cnt1+1);
                if(tmp_blue < 0) break;
            } 
            else{
                tmp_red -= (cnt1+1);
                if(tmp_red < 0)  break;
            } 
            cnt1 += 1;
        }
        tmp_blue = blue, tmp_red = red;
        while(true){
            if(cnt2%2 == 0){
                tmp_red -= (cnt2+1);
                if(tmp_red < 0) break;
            } 
            else{
                tmp_blue -= (cnt2+1);
                if(tmp_blue < 0)  break;
            } 
            cnt2 += 1;
        }
        return max(cnt1,cnt2);
    }
};