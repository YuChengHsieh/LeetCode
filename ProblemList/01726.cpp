#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                int val = nums[i]*nums[j];
                mp[val] += 1;
            }
        }

        int ans = 0;
        for(auto& item: mp){
            ans += item.second*(item.second-1)/2;
        }
        return ans*8;
    }
};