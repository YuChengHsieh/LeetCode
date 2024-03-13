#include <vector>
using namespace std;
class Solution {
private:
    int greaterCount(vector<int>& nums, int val, bool insert){
        int start = 0, end = nums.size()-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(nums[mid] > val) end = mid - 1;
            else start = mid + 1;
        }
        // cout << end << endl;
        if(insert)  nums.insert(nums.begin()+start, val);
        return nums.size() - start;
    }
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> nums1, nums2, ans_nums1, ans_nums2, ans;
        nums1.push_back(nums[0]);
        nums2.push_back(nums[1]);
        ans_nums1.push_back(nums[0]);
        ans_nums2.push_back(nums[1]);
        
        for(int i=2; i<nums.size(); i++){
            int val1 = greaterCount(nums1,nums[i],false);
            int val2 = greaterCount(nums2,nums[i],false);
            if(val1 == val2){
                if(nums2.size() < nums1.size()){
                    greaterCount(nums2,nums[i],true);
                    ans_nums2.push_back(nums[i]);
                } 
                else{
                    greaterCount(nums1,nums[i],true);
                    ans_nums1.push_back(nums[i]);
                } 
            }
            else if(val1 > val2){
                greaterCount(nums1,nums[i],true);
                ans_nums1.push_back(nums[i]);
            } 
            else{
                greaterCount(nums2,nums[i],true);
                ans_nums2.push_back(nums[i]);
            } 
        }
        
        for(auto& num: ans_nums1){
            ans.push_back(num);
        }
        
        for(auto& num: ans_nums2){
            ans.push_back(num);
        }
        return ans;
    }
};