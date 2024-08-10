#include <vector>
using namespace std;
class Solution {
public:
    int inf = 10000000;

    int dp(int idx, vector<vector<int>>& dist, vector<int>& mem){
        if(idx == 0) return 0;
        if(mem[idx] != -1) return mem[idx];
        int ans = dp(idx-1,dist,mem)+1;
        for(auto& i: dist[idx]){
            ans = min(ans,dp(i,dist,mem)+1);
        }
        return mem[idx] = ans;
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<vector<int>> dist(n);
        

        for(auto& q: queries){
            dist[q[1]].push_back(q[0]);
            vector<int> mem(n,-1);
            int cnt = dp(n-1,dist,mem);
            ans.push_back(cnt);
        }

        return ans;

    }
};