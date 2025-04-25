#include <vector>
using namespace std;
class Solution {
    private:
        int check(int k, vector<int>& nums, vector<vector<int>>& queries){
            int size = nums.size();
            vector<int> diff(size+1,0);
            vector<int> prefix(size+1,0);
            for(int i=0; i<k; i++){
                diff[queries[i][0]] += queries[i][2];
                diff[queries[i][1]+1] -= queries[i][2];
            }
    
            prefix[0] = diff[0];
            for(int i=1; i<size; i++){
                prefix[i] = prefix[i-1] + diff[i];
                // cout << prefix[i] << ' ';
            }
            // cout << endl;
            for(int i=0; i<size; i++){
                if(nums[i] > prefix[i]) return false;
            }
            return true;
        }
    
    public:
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            // binary search
            int start = 0, end = queries.size();
            while(start <= end){
                int mid = start + (end-start)/2;
                if(check(mid,nums,queries)) end = mid - 1;
                else start = mid + 1;
            }
            return start > queries.size() ? -1 : start;
        }
    };