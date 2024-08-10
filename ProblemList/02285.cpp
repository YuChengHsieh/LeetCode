#include <vector>
using namespace std;
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> cnt(n,0);
        for(auto& road: roads){
            cnt[road[0]] += 1;
            cnt[road[1]] += 1;
        }
        sort(cnt.begin(), cnt.end());
        long long ans = 0;
        for(long long i=0; i<cnt.size(); i++){
            ans += cnt[i]*(i+1);
        }
        return ans;
    }
};