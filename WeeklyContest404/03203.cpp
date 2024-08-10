#include <vector>
#include <queue>
using namespace std;
class Solution {
private:
    int furthest_node(vector<vector<int>>& graph){
        queue<int> q;
        vector<bool> visited(graph.size(),false);
        q.push(0);
        visited[0] = true;
        int cnt = graph.size()-1;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto &nextn: graph[cur]){
                if(!visited[nextn]){
                    visited[nextn] = true;
                    cnt --;
                    if(cnt == 0) return nextn;
                    q.push(nextn);
                }
            }
        }
        return -1;
    }

    int max_distance(vector<vector<int>>& graph, int fur_node){
        if(fur_node == -1) return 0;
        queue<int> q;
        vector<bool> visited(graph.size(),false);
        q.push(fur_node);
        visited[fur_node] = true;
        int max_dis = 0;
        while(!q.empty()){
            int sz = q.size();
            if(q.size() == 0) break;
            max_dis += 1;
            for(int i=0; i<sz; i++){
                int cur = q.front();
                q.pop();
                for(auto &nextn: graph[cur]){
                    if(!visited[nextn]){
                        visited[nextn] = true;
                        q.push(nextn);
                    }
                }
            }
        }
        return max_dis;
    }

public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int m = edges1.size()+1, n = edges2.size()+1;
        vector<vector<int>> graph1(m), graph2(n);
        for(auto& e: edges1){
            graph1[e[0]].push_back(e[1]);
            graph1[e[1]].push_back(e[0]);
        }
        for(auto& e: edges2){
            graph2[e[0]].push_back(e[1]);
            graph2[e[1]].push_back(e[0]);
        }

        int fur_node1 = furthest_node(graph1);
        int fur_node2 = furthest_node(graph2);

        int max_dis1 = max_distance(graph1,fur_node1)-1;
        int max_dis2 = max_distance(graph2,fur_node2)-1;

        return max({max_dis1, max_dis2, (max_dis1+1)/2+(max_dis2+1)/2+1});
    }
};