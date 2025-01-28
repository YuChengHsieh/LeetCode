#include <queue>
using namespace std;
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(auto& g: gifts) pq.push(g);

        for(int i=0; i<k; i++){
            int now = pq.top();
            pq.pop();
            pq.push(int(sqrt(now)));
        }

        long long ans = 0;
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};