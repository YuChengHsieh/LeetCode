#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> s_dict;
        unordered_map<char,int> t_dict;
        
        for(auto &ch: s){
            s_dict[ch] += 1;
        }
        for(auto &ch: t){
            t_dict[ch] += 1;
        }
        
        int diff = 0;
        for(auto &item: s_dict){
            if(!t_dict[item.first]) diff += item.second;
            else diff += max(0,item.second-t_dict[item.first]);
        }
        return diff;
    }
};