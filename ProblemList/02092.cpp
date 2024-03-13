#include <vector>
#include <map>
#include <unordered_set>
#include <queue>
using namespace std;

// BFS solution
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // BFS
        map<int,vector<pair<int,int>>> m;
        for(auto& meeting: meetings){
            m[meeting.back()].emplace_back(meeting[0],meeting[1]);
        }

        vector<bool> visited(n,false);
        visited[0] = true; visited[firstPerson] = true;
        queue<int> q;
        q.push(0);
        q.push(firstPerson);
        for(auto& item: m){
            unordered_map<int,vector<int>> graph;
            unordered_set<int> s;
            for(auto& meet: item.second){
                graph[meet.first].emplace_back(meet.second);
                graph[meet.second].emplace_back(meet.first);
                if(visited[meet.first]) s.insert(meet.first);
                if(visited[meet.second]) s.insert(meet.second);
            }

            for(auto& num: s) q.push(num);

            while(!q.empty()){
                int cur = q.front();
                q.pop();
                for(auto& nextn: graph[cur]){
                    if(!visited[nextn]){
                        visited[nextn] = true;
                        q.push(nextn);
                    }
                }
            }
        }
        
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(visited[i]) ans.emplace_back(i);
        }
        return ans;
    }
};

// union find solution
class UnionFind{
private:
    vector<int> parents;
public:
    UnionFind(int n){
        for(int i=0; i<n; i++) parents.emplace_back(i);
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
    void flush(int n){
        if(find(n) != find(0)) parents[n] = n;
    }
};
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int,vector<pair<int,int>>> m;
        for(auto& meeting: meetings){
            m[meeting.back()].push_back({meeting[0],meeting[1]});
        }

        UnionFind uf(n);
        uf.union_(0,firstPerson);
        for(auto& item: m){
            unordered_set<int> cur;
            for(auto& i: item.second){
                cur.insert(i.first);
                cur.insert(i.second);
                uf.union_(i.first, i.second);
            }
            for(auto& num: cur){
                uf.flush(num);
            }
        }
        vector<int> ans;
        int zero = uf.find(0);
        for(int i=0; i<n; i++){
            if(uf.find(i) == zero) ans.emplace_back(i);
        }
        return ans;
    }
};