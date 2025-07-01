#include <vector>
using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        // o(1) space complexity store results onto higher bit
        for(int i=0; i<nums.size(); i++){
            nums[i] += 1000*(nums[nums[i]]%1000);
        } 
        for(int i=0; i<nums.size(); i++){
            nums[i] /= 1000;
        }
        return nums;
    }
};

// o(n) space complexity
class Solution {
    public:
        vector<int> buildArray(vector<int>& nums) {
            vector<int> pos(nums.size(),0);
            for(int i=0; i<nums.size(); i++){
                pos[nums[nums[i]]] = i;
            }
            
            for(int i=0; i<nums.size(); i++){
                nums[pos[i]] = i;
            }
            return nums;
        }
    };