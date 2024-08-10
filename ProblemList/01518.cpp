class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int cur = numBottles, ans = numBottles;
        while(cur/numExchange != 0){
            int val = cur/numExchange;
            cur = val + cur%numExchange;
            ans += val;
        }
        return ans;
    }
};