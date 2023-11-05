#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int size_ = nums.size()+1;
        vector<int> prefix(size_,0);
        vector<int> suffix(size_,0);
        for(int i=1; i<size_; i++) prefix[i] = prefix[i-1]+nums[i-1];
        for(int i=size_-2; i>=0; i--) suffix[i] = suffix[i+1]+nums[i];
        for(int i=0; i<size_-1; i++) if(prefix[i]==suffix[i+1]) return i;
        return -1;
    }
};