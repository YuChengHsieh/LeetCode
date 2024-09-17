#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        map<int,int> vowel;
        int ans = 0;
        int num = 0;

        vowel[num] = -1;
        map<char,int> cmp;
        cmp['a'] = 0;
        cmp['e'] = 1;
        cmp['i'] = 2;
        cmp['o'] = 3;
        cmp['u'] = 4;
        for(int i=0; i<s.size(); i++){
            if(cmp.count(s[i])){
                num ^= 1 << cmp[s[i]];
            }
            if(vowel.count(num)){
                ans = max(ans,i-vowel[num]);
            }else{
                vowel[num] = i;
            }
        }
        return ans;
    }
};