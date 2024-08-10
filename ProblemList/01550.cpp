#include <vector>
using namespace std;
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt = 0;
        for(auto& num: arr){
            if(num%2 == 1){
                cnt += 1;
                if(cnt == 3) return true;
            }
            else cnt = 0;
        }
        return false;
    }
};