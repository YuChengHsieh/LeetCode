#include <vector>
#include <sstream>
// #include <string>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size() == 0) return ans;
        stringstream ss;
        ss << nums[0];
        int cnt = 1;
        int prev = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i] - 1 != prev){
                if(cnt > 1) ss << "->" << prev;
                ans.push_back(ss.str());
                ss.str("");
                ss << nums[i];
                cnt = 0;
            }
            cnt += 1;
            prev = nums[i];
        }
        
        if(cnt > 1) ss << "->" << prev;
        ans.push_back(ss.str());
        return ans;
    }
};