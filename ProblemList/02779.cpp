#include <vector>
#include <map>
using namespace std;

// using sliding window
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        for(auto& n: nums) n += k;
        int left = 0, ans = 0;    
        for(int right=0; right<nums.size(); right++){
            while(nums[left] < nums[right] - 2*k) left++;
            ans = max(ans,right-left+1);
        }
        return ans;
    }
};

// using map
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int max_num = INT_MIN, min_num = INT_MAX;
        map<int,int> mp_low, mp_high;

        for(auto& num: nums){
            mp_low[num-k] += 1;
            mp_high[num+k] += 1;
            max_num = max(max_num,num);
            min_num = min(min_num,num);
        }
        
        int cnt = 0, ans = 0;
        for(auto& item: mp_low){
            if(item.first < min_num){
                cnt += item.second;
                ans = max(cnt,ans);
            } 
            else break;
        }

        for(int i=min_num; i<=max_num; i++){
            cnt += mp_low[i];
            cnt -= mp_high[i-1];
            ans = max(ans,cnt);
            // cout << i << ' ' << cnt << endl;
        }

        return ans;
    }
};