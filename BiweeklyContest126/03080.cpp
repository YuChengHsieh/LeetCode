#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<long long> ans;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<bool> marked(n,false);
        
        long long sum = 0;
        for(int i=0; i<n; i++){
            pq.push({nums[i],i});
            sum += nums[i];
        }
        
        for(auto& query: queries){
            if(sum == 0){
                ans.push_back(0);
                continue;
            } 
            if(!marked[query[0]]){
                marked[query[0]] = true;
                sum -= nums[query[0]];
            }
            for(int i=0; i<query[1]; i++){
                while(!pq.empty() && marked[pq.top().second]){
                    auto [val, idx] = pq.top();
                    pq.pop();
                }
                if(!pq.empty()){
                    auto [val, idx] = pq.top();
                    pq.pop();
                    marked[idx] = true;
                    sum -= val;
                }else break;
                if(sum == 0) break;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};