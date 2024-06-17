#include <vector>
#include <bitset>
using namespace std;
class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        const int num_bit = 100000;
        
        bitset<num_bit> cnts;
        cnts[0] = 1;
        bitset<num_bit> mask;
        int cur = 0;
        for(auto val: rewardValues){
            while(cur < val) mask.set(cur++);
            cnts |= (cnts & mask) << val;
        }
        
        int ans = cnts.size()-1;
        while(!cnts[ans]) ans --;
        return ans;
    }
};