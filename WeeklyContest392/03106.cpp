#include<string>
using namespace std;
class Solution {
public:
    string getSmallestString(string s, int k) {
        string ans = "";
        for(auto& ch: s){
            if(k >= min('a'+26-ch,ch-'a')){
                ans += 'a';
                k -= min('a'+26-ch,ch-'a');
            }else{
                ans += ch-k;
                k = 0;
            }
        }
        return ans;
    }
};