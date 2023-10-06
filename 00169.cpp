#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
// Moore Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int candidate = 1000000007;
        for(auto &num : nums){
            if(cnt == 0){
                candidate = num;
            }
            if(candidate == num) cnt += 1;
            else cnt -= 1;
        }
        return candidate;
    }
};