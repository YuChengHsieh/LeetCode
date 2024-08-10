#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        map<int,vector<int>> mp;
        vector<int> transform;
        for(int i=0; i<nums.size(); i++){
            int val = nums[i];
            int result_val = 0;
            int idx = 0;
            if(val == 0) result_val = mapping[0];
            while(val != 0){
                result_val += mapping[(val%10)]*pow(10,idx);
                val /= 10;
                idx += 1;
            }
            if(!mp.count(result_val)) transform.push_back(result_val);
            mp[result_val].push_back(nums[i]);
        }

        sort(transform.begin(), transform.end());
        int idx = 0;
        for(int i=0; i<transform.size(); i++){
            for(auto& num: mp[transform[i]]){
                nums[idx] = num;
                idx ++;
            }
        }
        return nums;
    }
};