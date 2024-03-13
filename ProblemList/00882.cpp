#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        // BFS
        vector<vector<pair<int,int>>> graph(n, vector<pair<int,int>>(n)); 
        vector<vector<int>> connected_nodes(n); 
        for(int i=0; i<edges.size(); i++){
            graph[edges[i][0]][edges[i][1]] = {edges[i][2],0};
            graph[edges[i][1]][edges[i][0]] = {edges[i][2],0};
            connected_nodes[edges[i][0]].emplace_back(edges[i][1]);
            connected_nodes[edges[i][1]].emplace_back(edges[i][0]);
        }

        
        vector<bool> visited(n,false);
        // visited[0] = true;

        priority_queue<pair<int,int>> pq;
        pq.push({maxMoves+1,0});

        int cnt = 0;
        while(!pq.empty()){
            auto [move, cur] = pq.top();
            pq.pop();
            if(visited[cur]) continue;
            visited[cur] = true;
            move -= 1;
            cnt += 1;
            for(auto& nextn: connected_nodes[cur]){
                if(move-graph[cur][nextn].first <= 0){
                    if(move + graph[nextn][cur].second < graph[cur][nextn].first){
                        graph[cur][nextn].second += move;
                        cnt += move;
                    }else{
                        graph[cur][nextn].second += graph[cur][nextn].first - graph[nextn][cur].second;
                        cnt += graph[cur][nextn].first - graph[nextn][cur].second;
                    }
                }
                else if(!visited[nextn]){
                    cnt += graph[cur][nextn].first;
                    graph[cur][nextn].second = graph[cur][nextn].first;
                    pq.push({move-graph[cur][nextn].first, nextn});
                }
            }
        }
        return cnt;
    }
};