#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int size = minSize; 
        unordered_map<string,int> dict;
        
        int ans = 0;
        for(int i=0; i<=s.size()-size; i++){
            string substr = s.substr(i,size);
            unordered_set<char> subset (substr.begin(),substr.end());
            if(subset.size() <= maxLetters){
                dict[substr] += 1;
                ans = max(dict[substr],ans);
            }
            
        }
        return ans;
    }
};