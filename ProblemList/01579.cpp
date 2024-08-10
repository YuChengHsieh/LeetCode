#include <vector>
using namespace std;
class UnionFind {
private:
    vector<int> parents;
    int edge_count;
public:
    UnionFind(int n) : parents(n), edge_count(0) {
        for (int i = 0; i < n; ++i) {
            parents[i] = i;
        }
    }

    int find(int x) {
        if (x != parents[x]) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }

    void unionSets(int a, int b) {
        int r1 = find(a);
        int r2 = find(b);

        if (r1 != r2) { // is disjoint set
            parents[r2] = r1;
            edge_count += 1;
        }
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<vector<int>> edges1, edges2;
        UnionFind uf1(n), uf2(n);
        int cnt = 0;

        for(auto& e: edges){
            e[1] --, e[2] --;
            if(e[0] == 1) edges1.push_back({e[1],e[2]});
            else if(e[0] == 2) edges2.push_back({e[1],e[2]});
            else{
                if(uf1.find(e[1]) != uf1.find(e[2])){
                    uf1.unionSets(e[1],e[2]);
                    uf2.unionSets(e[1],e[2]);
                    cnt += 1;
                }
            }
        }

        for(auto& e: edges1){
            if(uf1.find(e[0]) != uf1.find(e[1])){
                uf1.unionSets(e[0],e[1]);
                cnt += 1;
            }
        }

        for(auto& e: edges2){
            if(uf2.find(e[0]) != uf2.find(e[1])){
                uf2.unionSets(e[0],e[1]);
                cnt += 1;
            }
        }
        
        int base1 = uf1.find(0);
        for(int i=1; i<n; i++){
            if(uf1.find(i) != base1) return -1;
        }

        int base2 = uf2.find(0);
        for(int i=1; i<n; i++){
            if(uf2.find(i) != base2) return -1;
        }

        return edges.size()-cnt;
    }
};