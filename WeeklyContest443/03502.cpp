#include <vector>
using namespace std;
class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        vector<int> ans;
        int min_val = INT_MAX;
        for(auto& c: cost){
            min_val = min(min_val,c);
            ans.push_back(min_val);
        }
        return ans;
    }
};
