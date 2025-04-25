#include <vector>
#include <queue>
using namespace std;
class Solution {
    public:
        int countPaths(int n, vector<vector<int>>& roads) {
            // dijkstra 
            if(n == 1) return 1;
            vector<vector<pair<int,long long>>> graph(n);
            for(auto& r: roads){
                graph[r[0]].push_back({r[1],(long long)r[2]});
                graph[r[1]].push_back({r[0],(long long)r[2]});
            }
            vector<long long> dist(n,LLONG_MAX);
            dist[0] = 0LL;
            vector<long long> ways(n,0LL);
            priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
            pq.push({0LL,0});
    
            int mod = 1e9+7;
            long long cut_off = LLONG_MAX;
            while(!pq.empty()){
                long long val;
                int cur;
                do{ 
                    auto item = pq.top();
                    val = item.first;
                    cur = item.second;
                    pq.pop();
                }while(!pq.empty() && val > dist[cur]);
                if(val > dist[cur] || val > cut_off) break;
                if(cur == n-1) cut_off = val;
    
                for(auto& next: graph[cur]){
                    auto [nextn, next_val] = next;
                    if(dist[nextn] >  val + next_val){
                        dist[nextn] =  val + next_val;
                        if(cur == 0) ways[nextn] = 1;
                        else ways[nextn] = ways[cur];
                        ways[nextn] %= mod;
                        pq.push({dist[nextn],nextn});
                    }else if(dist[nextn] == val + next_val){
                        if(cur == 0) ways[nextn] = 1;
                        else ways[nextn] += ways[cur];
                        ways[nextn] %= mod;
    
                    }
                }
            }
            return ways[n-1]%mod;
        }
    };