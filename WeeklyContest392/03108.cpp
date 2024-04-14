#include <vector>
using namespace std;
class UnionFind{
public:
    vector<int> parents;
    
    UnionFind(int n){
        
        for(int i=0; i<n; i++){
            parents.push_back(i);
        } 
    }
    int find(int cur){
        if(cur != parents[cur]) parents[cur] = find(parents[cur]);
        return parents[cur];
    }
    void union_(int a, int b){
        int pa = find(a);
        int pb = find(b);
        if(pa != pb) parents[pb] = pa;
        
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
//         union find
        UnionFind uf(n);
        for(auto edge: edges){
            uf.union_(edge[0],edge[1]);
        }
        
        
        unordered_map<int,int> min_map;
        for(auto edge: edges){
            if(min_map.count(uf.find(edge[0]))) min_map[uf.find(edge[0])] &= edge[2];
            else min_map[uf.find(edge[0])] = edge[2];
        }
        
        vector<int> ans;
        for(auto& q: query){
            if(q[0] == q[1]) ans.push_back(0);
            else if(uf.find(q[0]) == uf.find(q[1]) && min_map.count(uf.find(q[0]))) ans.push_back(min_map[uf.find(q[0])]);
            else ans.push_back(-1);
        }
        return ans;
    }
};