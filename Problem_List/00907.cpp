#include <vector>
using namespace std;
class Solution {
public:
    // monotonic stack
    int sumSubarrayMins(vector<int>& arr) {
        long long int sum = 0;
        int MOD = pow(10,9)+7;
        vector<pair<int,int>> look_up;
        for(int i=0; i<arr.size(); i++){
            while(look_up.size() != 0){
                if(arr[i] > look_up[look_up.size()-1].first) break;
                look_up.pop_back();
            }
            look_up.push_back(make_pair(arr[i],i));

            int prev_idx = -1;
            for(auto &num: look_up){
                sum += num.first*(num.second - prev_idx);
                sum %= MOD;
                prev_idx = num.second;
            }
        }
        return int(sum%MOD);
    }
};