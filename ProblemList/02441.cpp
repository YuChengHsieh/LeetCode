#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> mem;
        int max_num = 0;
        for(auto num: nums){
            if(mem.count(-num)) max_num = max(max_num, abs(num));
            mem.insert(num);
        }
        return max_num == 0 ? -1 : max_num;
    }
};