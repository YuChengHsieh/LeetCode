#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> global_mp(26,0);
        for(auto ch: words[0]){
            global_mp[ch-'a'] += 1;
        }

        for(auto& w: words){
            vector<int> local_mp(26,0);
            for(auto& ch: w){
                local_mp[ch-'a'] += 1;
            }
            for(int i=0; i<26; i++){
                global_mp[i] = min(global_mp[i],local_mp[i]);
            }
        }
        
        vector<string> ans;
        for(int i=0; i<26; i++){
            for(int j=0; j<global_mp[i]; j++){
                ans.push_back(string(1,'a'+i));
            }
        }
        return ans;
    }
};