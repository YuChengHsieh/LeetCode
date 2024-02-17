#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // floyd warshell
        unordered_map<string,int> map;
        int total_node = 0;
        for(auto &eq: equations){
            if(!map.count(eq[0])){
                map[eq[0]] = total_node;
                total_node += 1;
            }
            if(!map.count(eq[1])){
                map[eq[1]] = total_node;
                total_node += 1;
            }
        } 

        vector<vector<double>> graph(total_node, vector<double>(total_node,0.0));
        for(int i=0; i<total_node; i++){
            graph[i][i] = 1;
        }
        
        for(int i=0; i<equations.size(); i++){
            graph[map[equations[i][0]]][map[equations[i][1]]] = values[i];
            graph[map[equations[i][1]]][map[equations[i][0]]] = 1/values[i];
        }

        for(int i=0; i<total_node; i++){
            for(int j=0; j<total_node; j++){
                for(int k=0; k<total_node; k++){
                    if(i != j && graph[j][k] == 0.0 && (graph[j][i] != 0.0 && graph[i][k] != 0.0)){
                        graph[j][k] = graph[j][i]*graph[i][k];
                        // graph[j][i] = graph[j][k]*graph[k][i];
                    }
                }
            }
        }

        vector<double> ans;
        for(auto query: queries){
            if(!map.count(query[0]) || !map.count(query[1]) || graph[map[query[0]]][map[query[1]]] == 0.0) ans.push_back(-1.0);
            else ans.push_back(graph[map[query[0]]][map[query[1]]]);
        }

        return ans;
    }
};