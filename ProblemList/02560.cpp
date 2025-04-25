#include <vector>
using namespace std; 
class Solution {
    private:
        int check(int val, vector<int>& nums, int k){
            int cnt = 0;
            bool prev = false;
            for(auto& num: nums){
                if(num <= val){
                    if(prev) prev = false;
                    else{
                        cnt ++;
                        prev = true;
                    } 
                    
                }else prev = false;
            }
            return cnt >= k;
        }
    public:
        int minCapability(vector<int>& nums, int k) {
            int start = INT_MAX, end = 0;
            for(auto& num: nums){
                start = min(num, start);
                end = max(num, end);
            }
    
            while(start <= end){
                int mid = start + (end-start)/2;
                if(check(mid, nums, k)) end = mid - 1;
                else start = mid + 1;
            }
            return start;
        }
    };