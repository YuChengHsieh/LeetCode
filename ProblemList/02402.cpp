#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end(),[](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });

        priority_queue <pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        priority_queue <int, vector<int>, greater<int>> room_available;
        for(int i=0; i<n; i++){
            room_available.push(i);
        }
        vector<int> use_cnt(n,0);
        int meet_idx = 0;
        long long time = meetings[0][0];
        while(meet_idx < meetings.size()){

            if(room_available.empty()){
                auto [end_time, room_num] = pq.top();
                pq.pop();
                time = end_time;
                room_available.push(room_num);
            }
            // pop from queue
            while(!pq.empty() && pq.top().first <= time){
                room_available.push(pq.top().second);                
                pq.pop();   
            }
                        
            while(!room_available.empty() && meetings[meet_idx][0] <= time){
                int room_num = room_available.top();
                room_available.pop();
                use_cnt[room_num] += 1;
                pq.push({time+meetings[meet_idx][1]-meetings[meet_idx][0], room_num});
                meet_idx += 1;
                if(meet_idx >= meetings.size()) break;
            }
            if(meet_idx < meetings.size()) time = max(time, (long long)meetings[meet_idx][0]);
        }
        
        int max_val = 0, max_num = -1;
        for(int i=0; i<use_cnt.size(); i++){
            // cout << i << ' ' << use_cnt[i] << endl;
            if(use_cnt[i] > max_val){
                max_val = use_cnt[i];
                max_num = i;
            }
        }
        return max_num;
    }
};