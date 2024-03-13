#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto&num: nums){
            m[num] += 1;
            if(m[num] > 2) return false;
        }
        return true;
    }
};