#include <vector>
using namespace std;
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int ans = INT_MIN;
        for(int i=0; i<energy.size(); i++){
            if(i >= k) energy[i] = max(energy[i],energy[i]+energy[i-k]);
            if(i >= energy.size()-k) ans = max(ans,energy[i]);
        }
        return ans;
    }
};