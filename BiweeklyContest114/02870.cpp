#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> dict;
        for(auto &num:nums ){
            dict[num] += 1;
        }
        int cnt = 0;
        for(auto &i: dict){
            if(i.second == 1) return -1;
            cnt += ceil(float(i.second)/3.);
        }
        return cnt;
    }
};