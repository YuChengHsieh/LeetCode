#include <queue>
using namespace std;
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        // priority queue
        priority_queue<int> pq;
        for(auto& num: nums){
            pq.push(num);
        }

        long long score = 0;
        for(int i=0; i<k; i++){
            int val = pq.top();
            score += val;
            pq.pop();
            pq.push(int(ceil((double)val/3.0)));
        }

        return score;
    }
};