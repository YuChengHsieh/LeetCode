// recursive TLE
# include<iostream>
# include<vector>
using namespace std;
class Solution {
public:
    int ans = INT_MAX;
    void rec(int idx, int amount, int coin_num, vector<int>& coins){
        if(idx >= coins.size() or amount < 0) return;
        if(amount == 0){
            if(coin_num<ans) ans = coin_num;
            return;
        }
        amount -= coins[idx];
        rec(idx,amount,coin_num+1,coins);
        amount += coins[idx];
        rec(idx+1,amount,coin_num,coins);
        return;

    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        rec(0,amount,0,coins);
        return (ans==INT_MAX)?-1 : ans;
    }
};

// DP (beat 96%)
class Solution {
public:
    // DP
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<int> DP(amount+1,INT_MAX);
        DP[0] = 0;
        sort(coins.begin(),coins.end());
        int min;
        for(int i=1; i<=amount; i++){
            min = INT_MAX;
            for(auto &j : coins){
                if(i-j >=0 and DP[i-j] < min) min = DP[i-j];
            }
            // DP[i] = INT_MAX if min==INT_MAX else min+1
            DP[i] = (min==INT_MAX)?INT_MAX:(min+1);
        }
        // return -1 if DP[amount]==INT_MAX else DP[amount]
        return (DP[amount] == INT_MAX)?-1:DP[amount];
    }
};