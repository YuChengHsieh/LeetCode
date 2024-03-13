#include <vector>
#include <queue>
using namespace std;

// pq
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());
        int cnt = 0, min_val, max_val;
        while(!pq.empty() && pq.top() < k){
            long long min_val = pq.top(); pq.pop();
            long long max_val = pq.top(); pq.pop();
            pq.push(min_val*2 + max_val);
            cnt += 1;
        }
        return cnt;
    }
};