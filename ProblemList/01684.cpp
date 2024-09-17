#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        vector<bool> allows(26,false);
        for(auto& ch: allowed){
            allows[ch-'a'] = true;
        }
        for(auto& w: words){
            int cnt = 0;
            for(int i=0; i<w.size(); i++){
                if(!allows[w[i]-'a']) break;
                if(i == w.size()-1) ans ++;
            }
        }

        return ans;
    }
};