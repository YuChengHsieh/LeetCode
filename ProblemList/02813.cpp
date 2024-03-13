#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        unordered_set<int> saw_set;
        priority_queue<pair<int,int>> pq;
        priority_queue<int, vector<int>, greater<int>> seen_pq;
        for(auto& item: items){
            pq.push({item[0], item[1]});
        }

        long long category_cnt = 0, ans = 0, cur = 0;
        while(!pq.empty()){
            auto [profit, category] = pq.top();
            pq.pop();
            if(k > 0){
                cur += profit;
                k--;
                if(!saw_set.count(category)){
                    saw_set.insert(category);
                    category_cnt += 1;
                    cur += category_cnt*category_cnt - (category_cnt-1)*(category_cnt-1);
                }else seen_pq.push(profit);
            }else{
                if(!saw_set.count(category)){
                    saw_set.insert(category);
                    if(!seen_pq.empty()){
                        cur -= seen_pq.top();
                        seen_pq.pop();
                        category_cnt += 1;
                        cur += category_cnt*category_cnt - (category_cnt-1)*(category_cnt-1) + (long long)profit;
                    }else break;
                }
            }
            ans = max(ans,cur);
        }
        return ans;
    }
};