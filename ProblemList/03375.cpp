#include <vector>
#include <set>
using namespace std;
class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            set<int> targets;
            for(auto& num: nums){
                if(num < k) return -1;
                else if(num > k) targets.insert(num);
            } 
            return targets.size();
        }
    };