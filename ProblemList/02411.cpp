#include <vector>
#include <iostream>
using namespace std;
class Solution {
private:
    void bit_op(int num, vector<int>& bits, bool add){
        for(int i=0; i<=30; i++){
            if( ( num & (1 << i) ) != 0) bits[i] = add ? bits[i]+1 : bits[i]-1;
            else if((1 << i) > num) break; 
        }
        return;
    }
    int cal_cur(vector<int>& bits){
        int ans = 0;
        for(int i=0; i<=30; i++){
            if(bits[i] > 0) ans += (1 << i);
        }
        return ans;
    }
    void print_bit(vector<int>& bits){
        for(int i=5; i>=0; i--){
            cout << bits[i] << ' ';
        }
        cout << endl;
    }
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        // 2 pointer
        vector<int> max_or(nums.size(),0);
        max_or[max_or.size()-1] = nums.back();
        for(int i=max_or.size()-2; i>=0; i--) max_or[i] = max_or[i+1] | nums[i];
        // for(int i=0; i<nums.size(); i++) cout << max_or[i] << ' ';
        int left = 0, right = 0, cur_val = 0;
        vector<int> bits(31,0), ans;
        for(; right < nums.size(); right++){
            cur_val |= nums[right];
            bit_op(nums[right],bits,true);

            while(left <= right && cur_val == max_or[left]){
                ans.emplace_back(right-left+1);
                bit_op(nums[left],bits,false);
                cur_val = cal_cur(bits);
                left += 1;
                if(left >= nums.size()) break;
            }
        }
        return ans;
    }
};