#include <vector>
#include <set>
using namespace std;

// sliding window + set
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> st;
        int left = 0, cnt = 0;
        for(int right=0; right<nums.size(); right++){
            if(nums[right]%p == 0){
                if(cnt == k) while(nums[left++]%p != 0);
                else cnt ++;
            }
            for(int i=right; i>=left; i--){
                st.insert(vector<int>(nums.begin()+i,nums.begin()+right+1));
            }
        }
        return st.size();
    }
};