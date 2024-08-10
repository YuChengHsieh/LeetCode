#include <vector>
using namespace std;
class Solution {
private:
    int find(vector<int>& nums, int k){
        int left = 0, cnt = 0, ans = 0;
        for(int right = 0; right < nums.size(); right++){
            if(nums[right]%2 == 1){
                if(cnt == k){
                    while(nums[left++]%2 != 1);
                }else cnt ++;
            }
            ans += right-left+1;
        }
        return ans;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return find(nums,k) - find(nums,k-1);
    }
};