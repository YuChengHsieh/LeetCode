#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0; i<nums.size(); i++){
            pq.push({nums[i],i});
        }

        for(int i=0; i<k; i++){
            auto [num, idx] = pq.top();
            pq.pop();
            pq.push({num*multiplier,idx});
            nums[idx] = num*multiplier;
        }
        return nums;
    }
};