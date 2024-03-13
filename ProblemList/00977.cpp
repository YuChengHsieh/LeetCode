#include <map>
using namespace std;

// o(n) time and o(1) space
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // two pointer
        vector<int> ans(nums.size());
        int first = 0, last = nums.size()-1;
        for(int i=nums.size()-1; i>=0; i--){
            if(abs(nums[first]) > abs(nums[last])){
                ans[i] = nums[first]*nums[first];
                first += 1;
            }else{
                ans[i] = nums[last]*nums[last];
                last -= 1;
            }
        }
        return ans;
    }
};

// o(n) time and o(n) space
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        map<int,int> dict;
        for(auto& num: nums){
            dict[num*num] += 1;
        }
        
        vector<int> ans;
        for(auto& item: dict){
            for(int i=0; i<item.second; i++){
                ans.push_back(item.first);
            }
        }
        return ans;
    }
};