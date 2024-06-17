#include <vector>
using namespace std;
class Solution {
private:
    int mod = pow(10,9) + 7;
    int dp(int idx, int absent, int late, vector<vector<vector<int>>>& mem){
        if(absent == 2 || late == 3) return 0;
        if(idx == mem.size()) return 1;
        if(mem[idx][absent][late] != -1) return mem[idx][absent][late];
        int ans = dp(idx+1,absent,0,mem);
        ans = (ans+dp(idx+1,absent+1,0,mem))%mod;
        ans = (ans+dp(idx+1,absent,late+1,mem))%mod;
        return mem[idx][absent][late] = ans;
    }
public:
    int checkRecord(int n) {
        vector<vector<vector<int>>> mem(n, vector<vector<int>>(2, vector<int>(3,-1)));
        return dp(0,0,0,mem);
    }
};