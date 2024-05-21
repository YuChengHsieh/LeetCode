#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        unordered_map<int,int> table;
        for(int i=0; i<n; i++){
            table[score[i]] = i;
        }
        sort(score.begin(),score.end(),[](int a, int b){ return a > b; });

        vector<string> ans(n);
        for(int i=0; i<n; i++){
            if(i == 0) ans[table[score[i]]] = "Gold Medal";
            else if(i == 1) ans[table[score[i]]] = "Silver Medal";
            else if(i == 2) ans[table[score[i]]] = "Bronze Medal";
            else ans[table[score[i]]] = to_string(i+1);
        }
        return ans;
    }
};