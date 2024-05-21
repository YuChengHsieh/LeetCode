#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_map<string,int> needed_num;
        unordered_map<string, vector<string>> needed_i;
        for(int i=0; i<n; i++){
            needed_num[recipes[i]] = ingredients[i].size();
            for(int j=0; j<ingredients[i].size(); j++){
                needed_i[ingredients[i][j]].push_back(recipes[i]);
            }
        }

        queue<string> q;
        for(auto s: supplies) q.push(s);
        vector<string> ans;

        while(!q.empty()){
            string cur = q.front();
            if(needed_num.count(cur))ans.push_back(cur);
            q.pop();

            for(auto n: needed_i[cur]){
                needed_num[n] -= 1;
                if(needed_num[n] == 0) q.push(n);
            }
        }
        return ans;
    }
};