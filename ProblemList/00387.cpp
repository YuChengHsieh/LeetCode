#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> s_map(26,0);
        for(auto &ch: s){
            s_map[ch-'a'] += 1;
        }
        for(int i=0; i<s.size(); i++){
            if(s_map[s[i]-'a'] == 1) return i;
        }
        return -1;
    }
};