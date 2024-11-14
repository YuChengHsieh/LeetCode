#include <vector>
#include <map>
using namespace std;

class Solution {
private:    
    int bs(int val, vector<int>& vec){
        int start = 0, end = vec.size()-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(val >= vec[mid]) start = mid + 1;
            else end = mid - 1;
        }
        return end;
    }
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        map<int,int> mp;
        vector<int> bs_vec;
        for(auto& i: items){
            if(!mp.count(i[0])) bs_vec.push_back(i[0]);
            mp[i[0]] = max(mp[i[0]],i[1]);
        }
        sort(bs_vec.begin(), bs_vec.end());

        int max_val = 0;
        for(auto& item: mp){
            item.second = max(max_val,item.second);
            max_val = max(max_val,item.second);
        }

        vector<int> ans;
        for(auto& q: queries){
            int val = bs(q, bs_vec);
            ans.push_back(val == -1 ? 0 : mp[bs_vec[val]]);
        }

        return ans;
    }
};