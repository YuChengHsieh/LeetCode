class Solution {
public:
    // find the number that have the same root 
    int bulbSwitch(int n) {
        int val = 1, cnt = 0;
        while(val*val <= n){
            cnt += 1;
            val += 1;
        }
        return cnt;
    }
};