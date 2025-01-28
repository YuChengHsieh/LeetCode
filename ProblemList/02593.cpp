#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<bool> visited(n,0);
        for(int i=0; i<n; i++) pq.push({nums[i],i});
        long long ans = 0;
        while(!pq.empty()){
            auto [num, pos] = pq.top();
            pq.pop();
            if(!visited[pos]){
                visited[pos] = true;
                ans += num;
                if(pos-1 >= 0) visited[pos-1] = true;
                if(pos+1 < n) visited[pos+1] = true;
            }
        }
        return ans;
    }
};