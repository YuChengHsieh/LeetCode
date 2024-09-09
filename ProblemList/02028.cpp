#include <vector>
using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int total = rolls.size() + n;
        int val = total*mean;
        vector<int> ans(n,0);
        for(auto& r: rolls){
            val -= r;
        }
        if(val < n || val > 6*n) return vector<int>();
        for(int i=0; i<n; i++){
            ans[i] = val/n + (val%n > i);
        }
        return ans;
    }
};