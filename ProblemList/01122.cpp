#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp;
        for(auto& n: arr1){
            mp[n] += 1;
        }

        vector<int> ans;
        for(auto& n: arr2){
            for(int i=0; i<mp[n]; i++){
                ans.push_back(n);
            }
            mp.erase(n);
        }

        for(auto& item: mp){
            for(int i=0; i<item.second; i++){
                ans.push_back(item.first);
            }
        }
        return ans;
    }
};