#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> map;
        for(int i=0; i<=(int)s.size()-10; i++){
            map[s.substr(i,10)] += 1;
        }
        vector<string> ans;
        for(auto& item: map){
            if(item.second > 1) ans.emplace_back(item.first);
        }
        return ans;
    }
};