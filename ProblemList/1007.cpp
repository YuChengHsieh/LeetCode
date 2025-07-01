#include <vector>
using namespace std;
class Solution {
    public:
        int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
            vector<int> tops_cnt(6,0), bottoms_cnt(6,0), sub(6,0);
            int sz = tops.size();
            for(int i=0; i<sz; i++){
                tops_cnt[tops[i]-1] ++;
                bottoms_cnt[bottoms[i]-1] ++;
                if(tops[i] == bottoms[i]) sub[tops[i]-1] ++;
            }
            int ans = INT_MAX;
            for(int i=0; i<6; i++){
                if(tops_cnt[i] + bottoms_cnt[i] - sub[i] == sz) ans = min(ans,min(sz-tops_cnt[i],sz-bottoms_cnt[i]));
            }
    
            return ans == INT_MAX ? -1 : ans;
        }
    };