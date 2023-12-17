#include <vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max = -1, second_max = -1;
        for (auto &num: nums){
            if(num > max){
                second_max = max;
                max = num;
            }
            else if(num > second_max) second_max = num;
        }
        return (max-1)*(second_max-1);
    }
   
};