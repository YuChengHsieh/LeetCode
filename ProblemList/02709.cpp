#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;

// factor + unionfind
class UnionFind{
private:
    unordered_map<int,int> parents;
    set<int> set_input;
public:
    UnionFind(set<int>& input){
        set_input = input;
        for(auto& num: set_input) parents[num] = num;
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
    bool canTraverseAllPairs(vector<int>& nums) {
        if(nums.size() == 1) return true;
        set<int> set_input(nums.begin(),nums.end());
        if(set_input.count(1)) return false;
        unordered_map<int, int> connected;
        vector<pair<int,int>> edges;
        for(auto& num: set_input){
            for(int j=2; j<= (int) pow(num,0.5); j++){
                if(num%j == 0){
                    if(connected.count(j)) edges.emplace_back(connected[j],num);
                    else connected[j] = num;
                    if(num/j != j && connected.count(num/j)) edges.emplace_back(connected[num/j],num);
                    else connected[num/j] = num;
                }
            }
            connected[num] = num;
        }

        UnionFind uf(set_input);
        for(auto& edge: edges){
            uf.union_(edge.first,edge.second);
        }

        int val = uf.find(nums[0]);
        for(auto& num: set_input){
            if(uf.find(num) != val) return false;
        }
        return true;
    }
};

// factor + BFS
class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        if(nums.size() == 1) return true;
        unordered_set<int> set_input(nums.begin(),nums.end());
        if(set_input.count(1)) return false;
        unordered_map<int,vector<int>> graph;
        unordered_map<int,int> connect;
        // first construct edge with 2 nodes a,b that gcd(a,b) != 1
        for(auto& num: set_input){
            // get all the factor of number n, time complexity: o(sqrt(n))
            for(int j=2; j<=(int)pow(num,0.5)+1; j++){
                if(num % j == 0){
                    if(connect.count(j)){
                        int node = connect[j];
                        graph[node].emplace_back(num);
                        graph[num].emplace_back(node);
                    }
                    connect[j] = num;
                    if(connect.count(num/j)){
                        int node = connect[num/j];
                        graph[node].emplace_back(num);
                        graph[num].emplace_back(node);
                    }
                    connect[num/j] = num;
                }
            }
            if(connect.count(num)){
                int node = connect[num];
                graph[node].emplace_back(num);
                graph[num].emplace_back(node);
            }
            connect[num] = num;
        }

        queue<int> q;
        q.push(nums[0]);
        set_input.erase(nums[0]);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto& nextn: graph[cur]){
                if(set_input.count(nextn)){
                    set_input.erase(nextn);
                    q.push(nextn);
                }
            }
        }
        
        return set_input.size() == 0;
    }
};