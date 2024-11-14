#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> orig = arr;
        sort(arr.begin(), arr.end());
        map<int,int> mp;
        int prev_val = INT_MIN, cnt = 0;
        for(auto& val: arr){
            if(prev_val != val) cnt ++;
            mp[val] = cnt;
            prev_val = val;
        } 

        for(auto& val: orig){
            val = mp[val];
        }
        return orig;
    }
};