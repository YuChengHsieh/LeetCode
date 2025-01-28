#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](vector<int>& a, vector<int>& b){
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int ans = 0, max_prev = 0; 
        for(auto& e: events){
            pq.push({e[1],e[2]});
            while(!pq.empty() && e[0] > pq.top().first){
                max_prev = max(max_prev,pq.top().second);
                pq.pop();
            }
            ans = max(ans, e[2]+max_prev);
        }
        return ans;
    }
};