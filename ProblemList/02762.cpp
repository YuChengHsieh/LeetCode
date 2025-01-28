#include <queue>
#include <map>
#include <vector>
#include <set>
using namespace std;

// map + priority queue
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int left = 0;
        priority_queue<int> max_pq;
        priority_queue<int, vector<int>, greater<int>> min_pq;
        map<int,int> mp_max, mp_min;
        long long ans = 0;
        for(int right = 0; right<nums.size(); right++){
            max_pq.push(nums[right]);
            min_pq.push(nums[right]);
            while(max_pq.top() - min_pq.top() > 2){
                if(nums[left] == max_pq.top()){
                    max_pq.pop();
                    int val = max_pq.top();
                    for(int i=0; i<mp_max[val]; i++){
                        max_pq.pop();
                    }
                    mp_max[val] = 0;
                } 
                else mp_max[nums[left]] ++;

                if(nums[left] == min_pq.top()){
                    min_pq.pop();
                    int val = min_pq.top();
                    for(int i=0; i<mp_min[val]; i++){
                        min_pq.pop();
                    }
                    mp_min[val] = 0;
                } 
                else mp_min[nums[left]] ++;
                
                left ++;
            }
            ans += right - left + 1;
        }
        return ans;
    }
};

// multiset
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int left = 0;
        multiset<int> st;
        long long ans = 0;
        for(int right = 0; right<nums.size(); right++){
            st.insert(nums[right]);
            while(*prev(st.end())-*st.begin() > 2){
                auto it = st.find(nums[left]);
                st.erase(it);
                left ++;
            }
            ans += right - left + 1;
        }
        return ans;
    }
};