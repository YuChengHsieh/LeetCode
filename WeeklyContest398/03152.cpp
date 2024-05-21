#include <vector>
using namespace std;

// prefix sum o(n)
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int prev = nums[0];
        vector<int> prefix(nums.size(), 0);
        for(int i=1; i<nums.size(); i++){
            if((prev%2 == 0 && nums[i]%2 == 0) || (prev%2 == 1 && nums[i]%2 == 1) ) prefix[i] = prefix[i-1]+1;
            else prefix[i] = prefix[i-1];
            prev = nums[i];
        }

        vector<bool> ans;
        for(auto& q: queries){
            if(prefix[q[1]] - prefix[q[0]] == 0) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};

// binary search o(nlogn)
class Solution {
public:
    int check(int mid, vector<int>& query, vector<int>& invalid){
        if(query[1] <= invalid[mid]-1) return 0;
        else if(query[0] >= invalid[mid]) return 1;
        else return 2;
    }
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> invalid;
        int prev = nums[0];
        for(int i=1; i<nums.size(); i++){
            if((prev%2 == 0 && nums[i]%2 == 0) || (prev%2 == 1 && nums[i]%2 == 1) ) invalid.push_back(i);
            prev = nums[i];
        }
        
        vector<bool> ans;
        for(auto& query: queries){
            int start = 0, end = invalid.size()-1;
            bool f = true;
            while(start <= end){
                int mid = start+(end-start)/2;
                int ret = check(mid, query, invalid);
                if(ret == 2){
                    ans.push_back(false);
                    f = false;
                    break;
                }
                if(ret == 1) start = mid+1;
                else end = mid-1;
            }
            if(f) ans.push_back(true);
        }
        return ans;
    }
};