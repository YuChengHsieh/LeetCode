#include <unordered_map>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,int> pattern_map;
        unordered_map<string, int> s_map;
        stringstream ss(s);
        vector<string> tokens;
        string token;
        while(getline(ss,token,' ')){
            tokens.push_back(token);
        }
        if(tokens.size() != pattern.size()) return false;
        for(int i=0; i<pattern.size(); ++i){
            if(pattern_map[pattern[i]] != s_map[tokens[i]]) return false;
            pattern_map[pattern[i]] = i+1;
            s_map[tokens[i]] = i+1;           
        }
        return true;
    }
};