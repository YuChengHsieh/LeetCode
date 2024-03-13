#include <unordered_map>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_map<string, vector<string>> graph;
        if(bank.size() == 0) return -1;
        for(int i=0; i<bank.size(); i++){
            if(bank[i] == endGene) break;
            if(i == bank.size()-1) return -1;
        }
        bank.emplace_back(startGene);
        bank.emplace_back(endGene);

        for(int i=0; i<bank.size(); i++){
            for(int j=i+1; j< bank.size(); j++){
                int cnt = 0;
                for(int k=0; k<8; k++){
                    cnt += int(bank[i][k] == bank[j][k]);
                }
                if(cnt == 7){
                    graph[bank[i]].emplace_back(bank[j]);
                    graph[bank[j]].emplace_back(bank[i]);
                }
            }
        }

        queue<string> q;
        q.push(startGene);
        unordered_set<string> visited;
        int cnt = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                string cur = q.front();
                q.pop();
                if(cur == endGene) return cnt;
                for(auto& nextn: graph[cur]){
                    if(!visited.count(nextn)){
                        visited.insert(nextn);
                        q.push(nextn);
                    }
                }
            }
            cnt += 1;
        }
        return -1;
    }
};