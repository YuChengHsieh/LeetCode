#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(), 0);
        unordered_map<int,int> ball_map;
        unordered_map<int,int> color_map;
        for(int i=0; i<queries.size(); i++){
            if(ball_map.count(queries[i][0])){
                color_map[ball_map[queries[i][0]]] -= 1;
                if(color_map[ball_map[queries[i][0]]] == 0) color_map.erase(ball_map[queries[i][0]]);
            } 
            ball_map[queries[i][0]] = queries[i][1];
            color_map[queries[i][1]] += 1;
            ans[i] = color_map.size();
        }
        return ans;
    }
};