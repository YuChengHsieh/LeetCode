#include<vector>
using namespace std;
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0, cnt = 0, sacrifice = INT_MAX;
        for(long long num: nums){
            sum += max(num ^ k, num);
            cnt += (num ^ k) > num;
            sacrifice = min(sacrifice, abs(num - (num ^ k)));
        }
        return cnt%2 == 0 ? sum : sum - sacrifice;
    }
};