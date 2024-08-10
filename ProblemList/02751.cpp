#include <vector>
#include <stack>
#include <map>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<vector<int>> items;
        map<int,int> mp;
        for(int i=0; i<n; i++){
            items.push_back({positions[i],healths[i],directions[i] == 'R'});
            mp[positions[i]] = i;
        }

        sort(items.begin(), items.end());

        map<int,int> ans;
        stack<int> rights;
        for(int i=0; i<n; i++){
            if(items[i][2]) rights.push(i);
            else{
                while(!rights.empty() && items[rights.top()][1] < items[i][1]){
                    items[i][1] -= 1;
                    rights.pop();
                }

                if(!rights.empty()){
                    if(items[rights.top()][1] == items[i][1]){
                        rights.pop();
                    }else items[rights.top()][1] -= 1;
                }else{
                    ans[mp[items[i][0]]] = items[i][1];
                }
            }
        }
        while(!rights.empty()){
            ans[mp[items[rights.top()][0]]] = items[rights.top()][1];
            rights.pop();
        }

        vector<int> ans_vec;
        for(auto& item: ans){
            ans_vec.push_back(item.second);
        }
        return ans_vec;
    }
};