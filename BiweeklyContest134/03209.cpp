#include <vector>
using namespace std;
class Solution {
private:
    void setBitsCnt(vector<int>& bits_cnt, int num){
        for(int i=0; i<32; i++){
            if(num%2 == 1) bits_cnt[i] += 1;
            num /= 2;
        }
    }
    void unsetBitsCnt(vector<int>& bits_cnt, int num){
        for(int i=0; i<32; i++){
            if(num%2 == 1) bits_cnt[i] -= 1;
            num /= 2;
        }
    }
    bool valid(vector<int>& bits_cnt, int len, int k){
        int num = 0;
        for(int i=0; i<31; i++){
            if(bits_cnt[i] == len) num += (1 << i);
        }
        return num >= k;
    }
    long long countExactSubarrays(vector<int>& nums, int k){
        // sliding window
        long long ans = 0;
        int left = 0;
        vector<int> bits_cnt(32,0);
        for(int right=0; right<nums.size(); right++){
            setBitsCnt(bits_cnt,nums[right]);
            while(!valid(bits_cnt,right-left+1,k)){
                unsetBitsCnt(bits_cnt,nums[left++]);
            }
            ans += right-left+1;
        }
        return ans;
    }
public:
    long long countSubarrays(vector<int>& nums, int k) {
        return countExactSubarrays(nums,k) - countExactSubarrays(nums,k+1);
    }
};