#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<vector<int>> s_map(128, vector<int>()), t_map(128, vector<int>());
        for (int i = 0; i < s.size(); i++){
            s_map[s[i]].push_back(i);
            t_map[t[i]].push_back(i); 
        }
        
        sort(s_map.begin(), s_map.end(),[](vector<int> &a, vector<int> &b){
            return a.size() == b.size() && a.size() != 0 ? a[0] > b[0] : a.size() > b.size();
        });

        sort(t_map.begin(),t_map.end(),[](vector<int> &a, vector<int> &b){
            return a.size() == b.size() && a.size() != 0 ? a[0] > b[0] : a.size() > b.size();
        });

        for(int i=0; i<128; i++){
            if(s_map[i] !=  t_map[i]) return false;
            if(s_map[i].size() == 0 && t_map[i].size() == 0) break;
        }
        return true;
    }
};

// more concise method
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> s_map(128, -1), t_map(128, -1);
        for (int i = 0; i < s.size(); i++){
            if(s_map[s[i]] != t_map[t[i]]) return false;
            s_map[s[i]] = i;
            t_map[t[i]] = i; 
        }
        return true;
    }
};