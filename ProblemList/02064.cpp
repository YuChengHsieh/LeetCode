#include <vector>
using namespace std;

class Solution {
private:
    int check(int val, vector<int>& quantities){
        int cnt = 0;
        for(auto& q: quantities){
            cnt += q%val == 0 ? q/val : q/val+1;
        }
        return cnt;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int max_val = 0;
        for(auto& q: quantities) max_val = max(max_val, q);
        int start = 1, end = max_val;
        while(start <= end){
            int mid = start + (end-start)/2;

            if(check(mid, quantities) <= n) end = mid - 1;
            else start = mid + 1;
        }
        return start;
    }
};