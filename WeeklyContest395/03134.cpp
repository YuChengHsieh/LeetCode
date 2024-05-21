#include <vector>
using namespace std;
class Solution {
private:
    void cal_comb(int n, vector<long long>& comb){
        for(int i=1; i<=n; i++){
            comb[i] = comb[i-1]+i;
        }
        return;
    }

    long long cal(int target, vector<int>& nums){
        long long cnt = 0, left = 0;
        unordered_map<int,int> elements;
        for(int right = 0; right < nums.size(); right++){
            elements[nums[right]] += 1;
            while(elements.size() > target){
                elements[nums[left]] -= 1;
                if(elements[nums[left]] == 0) elements.erase(nums[left]);
                left += 1;
            }
            cnt += right-left+1;
        }
        return cnt;
    }
public:
    int medianOfUniquenessArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> comb(n+1,0);
        cal_comb(n,comb);
        int start = 1, end = n;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(comb[n]%2 == 0){
                if(cal(mid,nums) < comb[n]/2) start = mid + 1;
                else end = mid - 1;
            }else{
                if(cal(mid,nums) <= comb[n]/2) start = mid + 1;
                else end = mid - 1;
            }
            
        }
        return start;
    }
};