#include <vector>
using namespace std;
class Solution {
    public:
        vector<int> partitionLabels(string s) {
            vector<pair<int,int>> cnts(26,{-1,-1});
            for(int i=0; i<s.size(); i++){
                if(cnts[s[i]-'a'].first == -1) cnts[s[i]-'a'].first = i;
                cnts[s[i]-'a'].second = i;
            }
    
            sort(cnts.begin(), cnts.end(), [](pair<int,int>& a, pair<int,int>& b){
                return a.first < b.first;
            });
    
            vector<int> ans;
            int start = 0, end = 0;
            for(auto& i: cnts){
                if(i.first > end){
                    ans.push_back(end-start+1);
                    start = i.first;
                    end = i.second;
                }else end = max(end, i.second);
            }
            ans.push_back(end-start+1);
            return ans;
        }
    };