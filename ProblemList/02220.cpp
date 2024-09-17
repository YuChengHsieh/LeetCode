#include <vector>
using namespace std;
class Solution {
public:
    int minBitFlips(int start, int goal) {
        vector<bool> start_bit(32,false);
        vector<bool> goal_bit(32,false);
        
        int idx = 0;
        while(start != 0){
            start_bit[idx] = start%2;
            start /= 2;
            idx ++;
        }

        idx = 0;
        while(goal != 0){
            goal_bit[idx] = goal%2;
            goal /= 2;
            idx ++;
        }

        int ans = 0;
        for(int i=0; i<32; i++){
            ans += (start_bit[i] != goal_bit[i]);
        }

        return ans;
    }
};