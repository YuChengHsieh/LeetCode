#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int> s_dict, tar_dict;
        for(auto &ch:s ) s_dict[ch] += 1;
        for(auto &ch:target ) tar_dict[ch] += 1;

        int min_val = INT_MAX;
        for(auto &i: tar_dict) min_val = min(min_val,s_dict[i.first]/i.second);
        return min_val;
    }
};