#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<vector<int>, int> mp;
        for(auto& r: matrix){
            vector<int> key;
            if(r[0] == 0){
                for(auto& val: r) key.push_back(val);
            }else{
                for(auto& val: r) key.push_back(!val);
            }
            mp[key] += 1;
        } 

        int ans = 1;
        for(auto& item: mp){
            ans = max(ans,item.second);
        }
        return ans;
    }
};