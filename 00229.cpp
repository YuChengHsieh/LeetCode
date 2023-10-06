#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        vector<int> ans;
        for(auto &i: nums){
            map[i] += 1;
        }
        for(auto &item: map){
            if(item.second > nums.size()/3) ans.push_back(item.first);
        }
        return ans;
    }

};