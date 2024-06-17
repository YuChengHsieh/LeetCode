#include <string>
using namespace std;
class Solution {
public:
    int minimumChairs(string s) {
        int chair_cnt = 0, max_chair = 0;
        for(auto& ch: s){
            if(ch == 'E') chair_cnt += 1;
            else chair_cnt -= 1;
            max_chair = max(max_chair, chair_cnt);
        }
        return max_chair;
    }
};