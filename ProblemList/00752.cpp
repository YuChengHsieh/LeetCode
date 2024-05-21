#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
using namespace std;
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadend_set(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        if(deadend_set.count("0000")) return -1;
        queue<string> q;
        q.push("0000");
        visited.insert("0000");

        int ans = -1, step = 0;
        while(!q.empty() && ans == -1){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                string cur = q.front();
                // cout << cur << endl;
                if(cur == target){
                    ans = step;
                    break;
                }
                q.pop();
                for(int j=0; j<4; j++){

                    string new_str1 = cur;
                    new_str1[j] = cur[j] == '9' ? '0' : cur[j]+1;
                    if(!deadend_set.count(new_str1) && !visited.count(new_str1)){
                        visited.insert(new_str1);
                        q.push(new_str1);
                    }

                    string new_str2 = cur;
                    new_str2[j] = cur[j] == '0' ? '9' : cur[j]-1;
                    if(!deadend_set.count(new_str2) && !visited.count(new_str2)){
                        visited.insert(new_str2);
                        q.push(new_str2);
                    }
                    
                }
            }
            // cout << endl;
            step += 1;
        }
        return ans;
        
    }
};