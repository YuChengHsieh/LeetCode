#include<vector>
#include<unordered_map>
#include<set>
#include<string>
using namespace std;
class Solution {
public:
    string minimizeStringValue(string s) {
        vector<int> cnts(26,0);
//         cnt, idx
        unordered_map<int,set<int>> map;
        string ans = "";
        int QM_num = 0;
        for(auto& ch: s){
            if(ch != '?') cnts[ch-'a'] += 1;
            else QM_num += 1;
            
        }
        
        for(int i=0; i<26; i++){
            map[cnts[i]].insert(i);
        }
        
        vector<int> ch_cnts(26,0);
        int cur = 0, sum = 0;
        while(sum < QM_num){
            for(auto& num: map[cur]){
                ch_cnts[num] += 1;
                map[cur+1].insert(num);
                sum += 1;
                if(sum >= QM_num) break;
            }
            cur += 1;
        }
        
        cur = 0;
        for(auto& ch: s){
            if(ch == '?'){
                while(ch_cnts[cur] == 0) cur += 1;
                ans += cur + 'a';
                ch_cnts[cur] -= 1;
            }
            else ans += ch;
        }
        
            
        return ans;
    }
};