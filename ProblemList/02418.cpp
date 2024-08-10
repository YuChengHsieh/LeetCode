#include <string>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        map<int,string> mp;
        for(int i=0; i<n; i++){
            mp[heights[i]] = names[i];
        }

        vector<string> ans;
        for(auto& item: mp){
            ans.push_back(item.second);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};