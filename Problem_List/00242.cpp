#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> s_dict, t_dict;
        for(auto ch:s) s_dict[ch] += 1;
        for(auto ch:t) t_dict[ch] += 1;
        return s_dict == t_dict;
    }
};