#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int max_len = 0, left = 0, right = 0;
        vector<int> ch_cnts(26,0);
        while(right < s.size()){
            if(ch_cnts[s[right]-'a'] < 2){
                ch_cnts[s[right]-'a'] += 1;
                right += 1;
            }else{
                ch_cnts[s[left]-'a'] -= 1;
                left += 1;
            }
            max_len = max(max_len,right-left);
        }
        return max_len;
    }
};