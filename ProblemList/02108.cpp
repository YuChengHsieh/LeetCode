#include <string>
using namespace std;
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto &word: words){
            for(int i=0; i<word.size(); i++){
                if(word[i] != word[word.size()-i-1]) break;
                if(i == word.size()/2) return word;
            }
        }
        return "";
    }
};