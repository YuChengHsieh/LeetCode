#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
private:
    bool strcmp(string a, string b){
        for(int i=0; i<a.size(); i++){
            if(a[i] != b[i]) return a[i] < b[i];
        }
        return true;
    }
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        vector<unordered_map<string, int>> vec_map(arr.size());
        unordered_map<string, int> total_map;
        
        int str_cnt = 0;
        for(auto& str: arr){
            for(int i=0; i<str.size(); i++){
                for(int j=1; j<=str.size() - i; j++){
                    vec_map[str_cnt][str.substr(i,j)] ++;
                    total_map[str.substr(i,j)] ++;
                }
            }
            str_cnt ++;
        }
        
        vector<string> ans(arr.size(),"");
        
        str_cnt = 0;
        for(auto& str: arr){
            for(int i=0; i<str.size(); i++){
                for(int j=1; j<=str.size()-i; j++){
                    if(total_map[str.substr(i,j)] - vec_map[str_cnt][str.substr(i,j)] == 0 && (ans[str_cnt] == "" || (j < ans[str_cnt].size() || (j == ans[str_cnt].size() && strcmp(str.substr(i,j), ans[str_cnt]))))){
                        ans[str_cnt] = str.substr(i,j);
                    }
                }
            }
            str_cnt ++;
        }
        return ans;
    }
};