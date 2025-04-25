#include <vector>
using namespace std;
class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            vector<bool> visited(101,false);
            for(int i=nums.size()-1; i>=0; i--){
                if(visited[nums[i]]) return i/3+1;
                visited[nums[i]] = true;
            }
            return 0;
        }
    };