#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double waiting_time = 0, idx=1, cur_time = customers[0][0];
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            cur_time += customers[q.front()][1];
            waiting_time += cur_time - customers[q.front()][0];
            q.pop();
            while(idx < customers.size() && cur_time >= customers[idx][0]){
                q.push(idx);
                idx += 1;
            }
            if(q.empty() && idx < customers.size()){
                cur_time = customers[idx][0];
                q.push(idx);
                idx += 1;
            }
        }
        return waiting_time/(double)customers.size();
    }
};