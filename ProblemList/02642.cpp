#include <vector>
using namespace std;
class Graph {
private:
    int size;
    vector<vector<int>> graph;
public:
    Graph(int n, vector<vector<int>>& edges) : size(n), graph(n, vector<int>(n,-1)) {
        for(const auto &edge: edges){
            graph[edge[0]][edge[1]] = edge[2];
        }
    }
    
    void addEdge(vector<int> edge) {
        graph[edge[0]][edge[1]] = edge[2];
    }
    
    int shortestPath(int node1, int node2) {
        // dijkstra
        vector<int> dist(size,INT_MAX);
        vector<bool> visited(size,false);
        dist[node1] = 0;
        for(int i=0; i<size; i++){
            
            int min = INT_MAX, nextn = -1;
            for(int j=0; j<size; j++){
                if(!visited[j] && dist[j] < min){
                    min = dist[j]; nextn = j;
                }
            }

            if(nextn == -1) break;
            if(nextn == node2) return min;
            visited[nextn] = true;

            for(int j=0; j<size; j++){
                if(!visited[j] && 
                graph[nextn][j] != -1 && 
                dist[nextn]+graph[nextn][j] < dist[j]) dist[j] = dist[nextn]+graph[nextn][j];
            }
        }
        return -1;
    }
};