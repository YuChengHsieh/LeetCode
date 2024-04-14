#include <vector>
using namespace std;
class Solution {
private:
    bool isPrime(int number) {
        if (number <= 1) {
            return false;
        }
        for (int i = 2; i * i <= number; i++) {
            if (number % i == 0) {
                return false;
            }
        }
        return true;
    }
public:
    int maximumPrimeDifference(vector<int>& nums) {
        // prime detection 
        int min_idx = INT_MAX, max_idx = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            if(isPrime(nums[i])){
                min_idx = min(min_idx,i);
                max_idx = max(max_idx,i);
            }
        }
        return max_idx-min_idx;
    }
};