#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans(pref.size(),0);
        ans[0] = pref[0];
        int cur = pref[0];
        for(int i=1; i<pref.size(); i++){
            ans[i] = cur ^ pref[i];
            cur ^= ans[i];
        }
        return ans;
    }
};