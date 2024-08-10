#include <vector>
using namespace std;
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;
        for(int i=0; i<rating.size(); i++){
            int left_cnt1 = 0, left_cnt2 = 0, right_cnt1 = 0, right_cnt2 = 0;
            for(int j=0; j<i; j++){
                if(rating[j] < rating[i]) left_cnt1 += 1;
                else left_cnt2 += 1;
            }

            for(int j=i+1; j<rating.size(); j++){
                if(rating[j] > rating[i]) right_cnt1 += 1;
                else right_cnt2 += 1;
            }
            ans += left_cnt1*right_cnt1 + left_cnt2*right_cnt2;
        }
        return ans;
    }
};