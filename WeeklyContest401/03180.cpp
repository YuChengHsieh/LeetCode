#include <vector>
#include <set>
using namespace std; 

// knapsack memorization
class Solution {
private:
    int dp(int idx, int reward, vector<int>& rewardValues, vector<vector<int>>& mem){
        if(idx == rewardValues.size()) return reward;
        if(mem[idx][reward] != -1) return mem[idx][reward];
        int ans = 0;
        if(reward < rewardValues[idx]) ans = max(ans, dp(idx+1,reward+rewardValues[idx],rewardValues,mem));
        ans = max(ans, dp(idx+1,reward,rewardValues,mem));
        return mem[idx][reward] = ans;
    }
public:
    int maxTotalReward(vector<int>& r) {
        set<int> s(r.begin(),r.end());
        vector<int> rewardValues(s.begin(), s.end());

        vector<vector<int>> mem(rewardValues.size(), vector<int>(4000, -1));
        sort(rewardValues.begin(),rewardValues.end());
        return dp(0,0,rewardValues,mem);
    }
};

// keep track of all elements inside
class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(),rewardValues.end());
        int sz = rewardValues.size();
        set<int> s;
        
        int max_val = 0;
        for(int i=0; i<sz; i++){
            s.insert(rewardValues[i]);
            max_val = max(max_val,rewardValues[i]);
            for(int val: s){
                if(val < rewardValues[i]){
                    if(max_val < val+rewardValues[i]) max_val = val+rewardValues[i];
                    s.insert(val+rewardValues[i]);
                }else break;
            }
        }
       
        
        return max_val;
    }
};