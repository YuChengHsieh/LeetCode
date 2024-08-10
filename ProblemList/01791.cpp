#include <vector>
using namespace std;
class Solution {
public:
    int findCenter(vector<vector<int>>& edges){
        vector<int> cnt(edges.size()+2);
        for(auto& edge: edges){
            cnt[edge[0]] += 1;
            cnt[edge[1]] += 1;
        }
        int ans = 0, max_val = 0;
        for(int i=0; i<cnt.size(); i++){
            if(cnt[i] > max_val){
                max_val = cnt[i];
                ans = i;
            }
        }
        return ans;
    }
};