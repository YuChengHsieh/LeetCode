#include <vector>
using namespace std;
class Solution {
private:
    long long inf = 1e12;
    long long dp(int ro_idx, int fac_idx, int limit, vector<int>& robot, vector<vector<int>>& factory, vector<vector<vector<long long>>>& mem){
        if(ro_idx == robot.size()) return 0;
        if(fac_idx == factory.size()) return inf;
        if(mem[ro_idx][fac_idx][limit] != -1) return mem[ro_idx][fac_idx][limit];
        long long ans = inf;
        if(limit > 0){
            ans = min(ans, abs((long long)robot[ro_idx] - (long long)factory[fac_idx][0]) + dp(ro_idx+1, fac_idx, limit-1, robot,factory,mem));
            ans = min(ans, abs((long long)robot[ro_idx] - (long long)factory[fac_idx][0]) + dp(ro_idx+1, fac_idx+1, fac_idx+1 == factory.size() ? 0 :factory[fac_idx+1][1], robot,factory,mem));
        } 
        ans = min(ans, dp(ro_idx, fac_idx+1, fac_idx+1 == factory.size() ? 0 :factory[fac_idx+1][1], robot, factory, mem));
        return mem[ro_idx][fac_idx][limit] = ans;
    }
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<vector<vector<long long>>> mem(robot.size(), vector<vector<long long>>(factory.size(), vector<long long>(101, -1)));
        return dp(0,0,factory[0][1],robot,factory,mem);
    }
};