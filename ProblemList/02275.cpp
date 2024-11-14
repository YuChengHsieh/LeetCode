#include <vector>
using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> cnts(32,0);
        for(auto c: candidates){
            int idx = 0;
            while(c > 0){
                cnts[idx] += c%2;
                c /= 2;
                idx ++;
            }
        }

        int ans = 0;
        for(int i=0; i<32; i++){
            ans = max(ans,cnts[i]);
        }
        return ans;
    }
};