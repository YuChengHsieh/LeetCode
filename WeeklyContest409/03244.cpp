#include <vector>
using namespace std;
class Solution {
private:
    int bs(int val, vector<int>&nums){
        int start = 0, end = nums.size()-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(val > nums[mid]) start = mid + 1;
            else end = mid - 1;
        }
        return start;
    }
public:
    int inf = 10000000;
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> nums(n,0);
        
        for(int i=0; i<n; i++){
            nums[i] = i;
        }

        int cnt = 0;
        for(auto& q: queries){
            int start = bs(q[0],nums);
            int end = bs(q[1],nums);
            
            int cnt = end-start-1;
            for(int i=0; i<cnt; i++){
                nums.erase(nums.begin()+start+1);
            }
            ans.push_back(nums.size()-1);
        }

        return ans;

    }
};