#include <vector>
using namespace std;

// brutal force
class Solution {
private:
    int ans = 0;
    void cnt_subsets(int idx, vector<int> tmp_vec, vector<int>& nums, int& max_or){
        if(idx > nums.size()) return;
        int or_num = 0;
        for(auto& num: tmp_vec){
            or_num |= num;
        }
        if(or_num == max_or) ans += 1;
        for(int i=idx; i<nums.size(); i++){
            tmp_vec.push_back(nums[i]);
            cnt_subsets(i+1,tmp_vec,nums,max_or);
            tmp_vec.pop_back();
        }
        return;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max_or = 0;
        for(auto& num: nums) max_or |= num;
        cnt_subsets(0,vector<int>(),nums,max_or);
        return ans;
    }
};

class Solution {
private:
    int ans = 0;
    void cnt_subsets(int idx, vector<int>& tmp_vec, vector<int>& nums, int& max_or){
        if(idx >= nums.size()) return;
        
        tmp_vec.push_back(nums[idx]);
        int or_num = 0;
        for(auto& num: tmp_vec) or_num |= num;
        if(or_num == max_or) ans += 1;
        cnt_subsets(idx+1,tmp_vec,nums,max_or);
        tmp_vec.pop_back();
        cnt_subsets(idx+1,tmp_vec,nums,max_or);
        return;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max_or = 0;
        vector<int> tmp_vec;
        for(auto& num: nums) max_or |= num;
        cnt_subsets(0,tmp_vec,nums,max_or);
        return ans;
    }
};