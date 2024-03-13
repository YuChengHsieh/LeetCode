#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> pair_vec;
        for(int i=0; i<profits.size(); i++){
            pair_vec.push_back({profits[i], capital[i]});
        }

        sort(pair_vec.begin(), pair_vec.end(), [](pair<int,int> a, pair<int,int> b){
            return a.second < b.second;
        });

        priority_queue<int> pq;
        int cur_capital = w;

        int idx = 0;
        for(; idx <pair_vec.size(); idx++){
            if(pair_vec[idx].second <= cur_capital) pq.push(pair_vec[idx].first);
            else break;
        }

        while(!pq.empty() && k > 0){
            cur_capital += pq.top();
            pq.pop();
            k--;
            while(idx < pair_vec.size()){
                if(pair_vec[idx].second <= cur_capital) pq.push(pair_vec[idx].first);
                else break;
                idx += 1;
            }
        }
        return cur_capital;
    }
};