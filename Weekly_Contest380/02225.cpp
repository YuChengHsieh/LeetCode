#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int> win_set;
        unordered_set<int> lose_set;
        unordered_set<int> lose_one_set;

        for(auto &match: matches){
            if(!lose_set.count(match[0]) && !win_set.count(match[0])) win_set.insert(match[0]);
            
            if(win_set.count(match[1])){
                win_set.erase(match[1]);
                lose_one_set.insert(match[1]);
                lose_set.insert(match[1]);
            }
            else if(!lose_one_set.count(match[1]) && !lose_set.count(match[1])){
                lose_one_set.insert(match[1]);
                lose_set.insert(match[1]);
            }
            else lose_one_set.erase(match[1]);
        }

        vector<vector<int>> ans;
        vector<int> win_vec (win_set.begin(),win_set.end());
        vector<int> lose_one_vec (lose_one_set.begin(),lose_one_set.end());
        sort(win_vec.begin(),win_vec.end());
        sort(lose_one_vec.begin(),lose_one_vec.end());

        ans.push_back(win_vec);
        ans.push_back(lose_one_vec);
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> losses(100001,0);
        for(auto &match: matches){
            if(losses[match[0]] == 0) losses[match[0]] = 1;
            if(losses[match[1]] == 1) losses[match[1]] = -1; 
            else losses[match[1]] -= 1; 
        }

        vector<vector<int>> ans(2, vector<int>());
        for(int i=1; i<losses.size(); i++){
            if(losses[i] == 1) ans[0].push_back(i);
            else if (losses[i] == -1) ans[1].push_back(i);
        }
        return ans;
    }
};