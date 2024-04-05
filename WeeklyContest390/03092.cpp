#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        priority_queue<pair<long long, int>> pq;
        unordered_map<int, long long> map;
        vector<long long> ans;
        for(int i=0; i<nums.size(); i++){
            map[nums[i]] += freq[i];
            pq.push({map[nums[i]], nums[i]});
            
            while(!pq.empty()){
                auto[f, num] = pq.top();
                if(map[num] == f) break;
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};