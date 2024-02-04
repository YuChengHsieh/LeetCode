#include <unordered_set>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char> vowels{'A','E','I','O','U','a','e','i','o','u'};
        vector<int> vowel_idx;
        vector<char> vowel_str;
        int n = s.size();
        for(int i=0; i<n; i++){
            if(vowels.count(s[i])){
                vowel_idx.push_back(i);
                vowel_str.push_back(s[i]);
            }
        }
        sort(vowel_str.begin(),vowel_str.end(), [] (char a, char b){return a < b;});
        
        for(int i=0; i<vowel_str.size(); i++){
            s[vowel_idx[i]] = vowel_str[i];
        }
        return s;
    }
};