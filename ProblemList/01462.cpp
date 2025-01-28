#include <vector>
#include <set>
using namespace std;
class Solution {
private:
    void dfs(int cur, vector<set<int>>& nodes, vector<vector<int>>& graph, vector<bool>& visited){
        set<int> s;
        for(auto& v: graph[cur]){
            if(!visited[v]){
                visited[v] = true;
                dfs(v,nodes,graph,visited);
            }
            s.insert(nodes[v].begin(),nodes[v].end());
            s.insert(v);
        }
        nodes[cur] = s;
        return;
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<set<int>> nodes(numCourses);
        vector<vector<int>> graph(numCourses);
        vector<bool> root(numCourses, true);
        vector<bool> visited(numCourses, false);
        for(auto& p: prerequisites){
            graph[p[0]].push_back(p[1]);
            root[p[1]] = false;
        }

        for(int i=0; i<numCourses; i++){
            if(root[i]){
                visited[i] = true;
                dfs(i,nodes,graph,visited);
            }
        }
        
        vector<bool> ans;
        for(auto&q : queries){
            ans.push_back(nodes[q[0]].count(q[1]) ? true : false);
        }
        return ans;
    }
};