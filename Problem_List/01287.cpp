#include <vector>
using namespace std;
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int prev = -1;
        int bound = arr.size()/4+1;
        int cnt = 1;
        for(auto &num: arr){
            if(num == prev) cnt += 1;
            else cnt = 1;
            if(cnt == bound) return num;
            prev = num;
        }
        return arr[arr.size()-1];
    }
};