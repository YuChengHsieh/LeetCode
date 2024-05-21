#include <vector>
using namespace std;
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int ans = 0, left = 0, right = people.size()-1;
        while(left <= right){
            if(people[left] + people[right] > limit) right -= 1;
            else{
                left += 1;
                right -= 1;
            }
                ans += 1;
        }
        return ans;
    }
};