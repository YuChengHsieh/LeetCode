#include<map>
#include<vector>
using namespace std;

// using map, space complexity o(n)
class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            map<int,int> mp;
            for(auto& num: nums) mp[num] ++;
            
            int maj = -1, max_cnt = 0;
            for(auto& item: mp){
                if(item.second > max_cnt){
                    max_cnt = item.second;
                    maj = item.first;
                }
            }
    
            int cnt = 0;
            for(int i=0; i<nums.size(); i++){
                if(nums[i] == maj) cnt ++;
                if(cnt > (i+1)/2 && max_cnt-cnt > (nums.size()-i-1)/2) return i;
            }
            return -1;
        }
    };

// using Boyer-Moore Majority Voting Algorithm, space complexity o(1)
class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            int cnt = 0, x = nums[0];
            for(auto& num: nums){
                if(num == x) cnt ++;
                else cnt --;
                if(cnt == 0){
                    x = num;
                    cnt = 1;
                }
            }
            int max_cnt = 0;
            for(auto& num: nums) if(num == x) max_cnt++;
            
            cnt = 0;
            for(int i=0; i<nums.size(); i++){
                if(nums[i] == x) cnt ++;
                if(cnt > (i+1)/2 && max_cnt-cnt > (nums.size()-i-1)/2) return i;
            }
            return -1;
        }
    };