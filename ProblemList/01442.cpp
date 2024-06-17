#include <vector>
using namespace std;
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int cnt = 0;
        for(int i=0; i<arr.size(); i++){
            int left_val = arr[i];
            int right_val = left_val;
            for(int j=i+1; j<arr.size(); j++){
                right_val ^= arr[j];
                if(right_val == 0) cnt += j-i;
            }
        }
        return cnt;
    }
};