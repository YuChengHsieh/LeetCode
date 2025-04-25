#include <vector>
#include <set>
#include <map>
using namespace std;
class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            // sliding window
            int ans = 0;
            set<int> st;
            for(auto& num: nums){
                st.insert(num);
            }
            
            int left = 0, distinct_size = st.size();
            map<int,int> mp;
            for(int right = 0; right < nums.size(); right++){
                mp[nums[right]]++;
                while(mp.size() == distinct_size){
                    mp[nums[left]] --;
                    if(mp[nums[left]] == 0) mp.erase(nums[left]);
                    left ++;
                }
                ans += left;
            }
            return ans;
        }
    };