#include <vector>
#include <map>
using namespace std;
// o(n)
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // o(n)
        int n = difficulty.size(), max_diff = 0;
        for(auto& d: difficulty){
            max_diff = max(max_diff,d);
        }

        vector<int> mp(max_diff+1,0);
        for(int i=0; i<n; i++){
            mp[difficulty[i]] = max(mp[difficulty[i]],profit[i]);
        }

        for(int i=1; i<=max_diff; i++){
            mp[i] = max(mp[i],mp[i-1]);
        }

        int ans = 0;
        for(auto&w :worker){
            ans += w > max_diff ? mp.back() : mp[w];
        }
        return ans;
    }
};

// o(nlogn) binary search
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        map<int,int> mp;
        for(int i=0; i<difficulty.size(); i++){
            mp[difficulty[i]] = max(mp[difficulty[i]],profit[i]);
        }

        int cur_max = 0;
        for(auto& item: mp){
            item.second = max(cur_max,item.second);
            cur_max = max(cur_max,item.second);
        }
        sort(difficulty.begin(),difficulty.end());

        int ans = 0;
        for(auto& w: worker){
            int start = 0, end = difficulty.size()-1;
            while(start <= end){
                int mid = start + (end-start)/2;
                if(w >= difficulty[mid]) start = mid+1;
                else end = mid-1;
            }
            if(end >= 0) ans += mp[difficulty[end]];
        }
        return ans;
    }
};