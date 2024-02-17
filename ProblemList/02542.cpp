#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> nums;
        for(int i=0; i<nums1.size(); i++){
            nums.push_back({nums1[i],nums2[i]});
        }

        sort(nums.begin(), nums.end(), [](pair<int,int> a, pair<int,int> b){
            return a.second > b.second;
        });

        priority_queue<int,vector<int>,greater<int>> pq;
        long long sum = 0;
        for(int i=0; i<k; i++){
            sum += nums[i].first;
            pq.push(nums[i].first);
        }
        long long ans = sum*nums[k-1].second;
        for(int i=k; i<nums.size(); i++){
            sum -= pq.top();
            pq.pop();
            sum += nums[i].first;
            pq.push(nums[i].first);
            ans = max(ans,sum * nums[i].second);
        }

        return ans;
    }
};