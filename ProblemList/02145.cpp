#include <vector>
using namespace std;

class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            int cur = 0, min_val = 0, max_val = 0;
            for(auto& d: differences){
                cur += d;
                min_val = min(min_val,cur);
                max_val = max(max_val,cur);
                if(upper - lower - (max_val - min_val) + 1 < 0) return 0;
            }
            return upper - lower - (max_val - min_val) + 1;
        }
    };

class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            long long cur = 0, min_val = 0, max_val = 0;
            for(auto& d: differences){
                cur += d;
                min_val = min(min_val,cur);
                max_val = max(max_val,cur);
            }
            return upper - lower - (max_val - min_val) + 1  > 0 ? upper - lower - (max_val - min_val) + 1 : 0;
        }
    };