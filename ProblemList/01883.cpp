#include <vector>
using namespace std;
class Solution {
private:
    double inf = 100000000;
    double dp(int idx, int skips, double speed, vector<int>& dist, vector<vector<double>>& mem){
        if(skips == -1) return inf;
        if(idx == mem.size()) return 0;
        if(mem[idx][skips] != -1) return mem[idx][skips];
        double ans = min(dp(idx+1,skips-1,speed,dist,mem)+(double)dist[idx]/speed-(1e-7), ceil(dp(idx+1,skips,speed,dist,mem))+(double)dist[idx]/speed);
        return mem[idx][skips] = ans;
    }
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int n = dist.size();
        vector<vector<double>> mem(n, vector<double>(n, -1));
        for(int i=0; i<n; i++){
            if(dp(0,i,(double)speed,dist,mem) <= hoursBefore) return i;
        }
        return -1;
    }
};