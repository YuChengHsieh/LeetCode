#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> mem;
        unordered_set<int> set;

        for(auto &pair: adjacentPairs){
            if(set.count(pair[0]) != 1) set.insert(pair[0]);
            else set.erase(pair[0]);
            if(set.count(pair[1]) != 1) set.insert(pair[1]);
            else set.erase(pair[1]);
            mem[pair[0]].push_back(pair[1]);
            mem[pair[1]].push_back(pair[0]);
        }

        vector<int> start(set.begin(),set.end());
        vector<int> ans;
        ans.push_back(start[0]);
        int cur = mem[start[0]][0];
        while(set.count(cur) != 1){
            ans.push_back(cur);
            set.insert(cur);
            auto next = mem[cur];
            for(auto &i: next){
                if(set.count(i) != 1) cur = i;
            }
        }
        ans.push_back(start[1]);
        return ans;
    }
};