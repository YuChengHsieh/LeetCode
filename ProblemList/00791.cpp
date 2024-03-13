#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> dict;
        for(auto&ch :s){
            dict[ch] += 1;
        }

        string ans;
        for(auto&ch : order){
            for(int i=0; i<dict[ch]; i++){
                ans += ch;
            }
            dict[ch] = 0;
        }

        for(int i=0; i<26; i++){
            for(int j=0; j<dict[i+'a']; j++){
                ans += i+'a';
            }
        }
        return ans;
    }
};