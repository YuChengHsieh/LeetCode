#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });

        int operation = 0, q_idx = 0, total = 0;
        priority_queue<int> pq;
        vector<int> diff(nums.size()+1,0);

        for(int i=0; i<nums.size(); i++){
            operation += diff[i];
            while(q_idx < queries.size() && queries[q_idx][0] <= i){
                pq.push(queries[q_idx][1]);
                q_idx ++;
            }

            nums[i] -= operation;
            while(nums[i] > 0 && !pq.empty() && pq.top() >= i){
                diff[pq.top()+1] -= 1;
                pq.pop();
                operation ++;
                total ++;
                nums[i] --;
            }
            
            if(nums[i] > 0) return -1;
        }
        return queries.size() - total;
    }
};


class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });

        int operation = 0, q_idx = 0;
        priority_queue<int> pq;
        vector<int> diff(nums.size()+1,0);

        for(int i=0; i<nums.size(); i++){
            operation += diff[i];
            while(q_idx < queries.size() && queries[q_idx][0] <= i){
                pq.push(queries[q_idx][1]);
                q_idx ++;
            }

            while(operation < nums[i] && !pq.empty() && pq.top() >= i){
                diff[pq.top()+1] -= 1;
                pq.pop();
                operation ++;
            }
            
            if(operation < nums[i]) return -1;
        }
        return pq.size();
    }
};