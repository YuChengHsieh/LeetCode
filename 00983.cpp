# include<iostream>
# include<vector>
using namespace std;
// Coin change problem
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int end_day = days[days.size()-1];
        vector<int> DP(end_day+1,0);

        for(auto &i : days){ DP[i]=1; }

        // calculate minimum travel cost of every day
        for(int i=1; i<=end_day; i++){
            // not travel day
            if(DP[i] == 0){ 
                DP[i] = DP[i-1];
                continue;
            }
            // calculate minimum travel cost of travel day
            if(i>=30) DP[i] = min({DP[i-1]+costs[0],DP[i-7]+costs[1],DP[i-30]+costs[2]});
            else if(i>=7) DP[i] = min({DP[i-1]+costs[0],DP[i-7]+costs[1],costs[2]});
            else DP[i] =  min({DP[i-1]+costs[0],costs[1],costs[2]});
        }
        return DP[end_day];
    }
};