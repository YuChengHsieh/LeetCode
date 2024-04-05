#include <vector>
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;
        for(auto& num: nums){
            if(first < second && second < num) return true;
            else if(num <= first) first = num;
            else if(num < second) second = num;
        }
        return false;
    }
};