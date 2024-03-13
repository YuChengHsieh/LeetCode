#include <vector>
using namespace std;

// Binary Search
class Solution {
private:
    bool check(int idx, vector<int>& nums, vector<int>& changeIndices){
        int n = nums.size();
        vector<pair<int,int>> late(n,{-1,-1});
        for(int i=idx; i>=0; i--){
            if(late[changeIndices[i]-1].second != -1) continue;
            late[changeIndices[i]-1] = {changeIndices[i]-1,i};
        }

        for(int i=0; i<n; i++){
            if(late[i].second == -1) return false;
        }

        sort(late.begin(), late.end(), [](pair<int,int>& a, pair<int,int>& b){
            return a.second < b.second;
        });
        
        int time = 0;
        for(auto& item: late){
            // cout << time << ' ' << item.first << ' ' << item.second << endl;
            if(time + nums[item.first] > item.second) return false;
            time += nums[item.first]+1;
        }
        return true;
    }
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int m = changeIndices.size();
        int start = nums.size()-1, end = m-1;
        if(start > end) return -1;
        while(start <= end){
            int mid = start+(end-start)/2;
            // cout << mid << ' ' << check(mid,nums,changeIndices) << endl;
            if(check(mid,nums,changeIndices)) end = mid-1;
            else start = mid+1;
        }
        return start == m ? -1 : start+1;
    }
};