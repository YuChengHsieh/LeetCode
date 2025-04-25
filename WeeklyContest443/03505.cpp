#include <vector>
#include <set>
using namespace std;
class Solution {
    private:
        long long inf = 1e13;
        long long dp(int idx, int k, vector<int>& nums, int x, vector<long long>& costs, vector<vector<long long>>& mem){
            if(k == 0) return 0LL;
            if(idx == nums.size()) return inf;
            if(mem[idx][k] != -1) return mem[idx][k];
            long long ans = inf;
            ans = min(ans,dp(idx+1,k,nums,x,costs,mem));
            if(idx+x-1 < nums.size()){
                ans = min(ans,costs[idx]+dp(idx+x,k-1,nums,x,costs,mem));
            }
            
            return mem[idx][k] = ans;
        }
    public:
        long long minOperations(vector<int>& nums, int x, int k) {
            vector<long long> costs;
            multiset<int> high;
            multiset<int, greater<int>> low;
            long long low_sum = 0, high_sum = 0;
    
            for(int i=0; i<x; i++){
                if(low.empty() || nums[i] <= *low.begin()){
                    low.insert(nums[i]);
                    low_sum += nums[i];
                }else{
                    high.insert(nums[i]);
                    high_sum += nums[i];
                }
    
                if(low.size() > high.size()+1){
                    high.insert(*low.begin());
                    high_sum += *low.begin();
                    low_sum -= *low.begin();
                    low.erase(low.begin());
                }else if(high.size() > low.size()){
                    low.insert(*high.begin());
                    high_sum -= *high.begin();
                    low_sum += *high.begin();
                    high.erase(high.begin());
                }
    
            }
    
            for(int i=x; i<nums.size(); i++){
                long long mid = x%2 ? *low.begin() : (*low.begin()+*high.begin())/2;
                costs.push_back(low.size()*1LL*mid - low_sum + high_sum - (high.size()*1LL*mid));
                
                int out_num = nums[i-x];
                if(low.count(out_num)){
                    low_sum -= out_num;
                    low.erase(low.find(out_num));
                }else{
                    high_sum -= out_num;
                    high.erase(high.find(out_num));
                }
    
                if(low.size() > high.size()+1){
                    high.insert(*low.begin());
                    high_sum += *low.begin();
                    low_sum -= *low.begin();
                    low.erase(low.begin());
                }else if(high.size() > low.size()){
                    low.insert(*high.begin());
                    high_sum -= *high.begin();
                    low_sum += *high.begin();
                    high.erase(high.begin());
                }
    
                if(low.empty() || nums[i] <= *low.begin()){
                    low_sum += nums[i];
                    low.insert(nums[i]);
                }else{
                    high_sum += nums[i];
                    high.insert(nums[i]);
                }
    
                if(low.size() > high.size()+1){
                    high.insert(*low.begin());
                    high_sum += *low.begin();
                    low_sum -= *low.begin();
                    low.erase(low.begin());
                }else if(high.size() > low.size()){
                    low.insert(*high.begin());
                    high_sum -= *high.begin();
                    low_sum += *high.begin();
                    high.erase(high.begin());
                }
    
            }
    
            long long mid = x%2 ? *low.begin() : (*low.begin()+*high.begin())/2;
            costs.push_back(low.size()*1LL*mid - low_sum + high_sum - (high.size()*1LL*mid));
    
            vector<vector<long long>> mem(nums.size(), vector<long long>(k+1,-1));
            return dp(0,k,nums,x,costs,mem);
        }
    };
    
    