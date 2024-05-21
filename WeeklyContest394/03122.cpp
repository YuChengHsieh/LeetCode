#include <vector>
using namespace std;
class Solution {
private:
    int dp(int idx, int val, int row_sz,vector<vector<int>>& cnt, vector<vector<int>>& mem){
        if(idx >= cnt.size()) return 0;
        if(mem[idx][val] != -1) return mem[idx][val];
        int ans = INT_MAX;
        for(int i=0; i<10; i++){
            if(i == val) continue;
            ans = min(ans,dp(idx+1,i,row_sz,cnt,mem)+row_sz-cnt[idx][i]);
        }
        return mem[idx][val] = ans;
    }
public:
    int minimumOperations(vector<vector<int>>& grid) {
        vector<vector<int>> mem (grid[0].size(), vector<int>(11,-1));
        vector<vector<int>> cnt (grid[0].size(), vector<int>(10,0));

        for(int i=0; i<grid[0].size(); i++){
            for(int j=0; j<grid.size(); j++){
                cnt[i][grid[j][i]] += 1;
            }
        }

        return dp(0,10,grid.size(),cnt,mem);

    }
};