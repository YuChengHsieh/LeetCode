#include <vector>
using namespace std;

// recursive
class Solution {
private:
    int dp(int isAlice, int idx, int m, vector<int>& piles, vector<vector<vector<int>>>& mem){
        if(idx >= piles.size()) return 0;
        if(mem[isAlice][idx][m] != -1) return mem[isAlice][idx][m];
        int ans = isAlice ? 0 : INT_MAX;
        int sum = 0;
        for(int i=1; i<=min(2*m,(int)piles.size()-idx); i++){
            sum += piles[idx+i-1];
            if(isAlice){
                ans = max(ans, sum + dp(0,idx+i,max(m,i),piles,mem));
            }   
            else{
                ans = min(ans, dp(1,idx+i,max(m,i),piles,mem));
            } 
        }
        return mem[isAlice][idx][m] = ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        vector<vector<vector<int>>> mem(2, vector<vector<int>>(100, vector<int>(100,-1)));
        return dp(1,0,1,piles,mem);
    }
};