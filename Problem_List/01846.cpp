#include <vector>
using namespace std;
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int val = 0;
        sort(arr.begin(),arr.end(), [](int a, int b) {return a < b;});
        for(auto num:arr){
            if(num <= val) continue;
            else val += 1;
        }
        return val;
    }
};