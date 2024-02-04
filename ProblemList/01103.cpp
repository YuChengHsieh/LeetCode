#include <vector>
using namespace std;
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people,0);
        int round=0;
        while(candies > 0){
            for(int i=0; i<num_people; i++){
                if(candies < round*num_people+(i+1)){
                    ans[i] += candies;
                    candies = 0;
                    break;
                }
                ans[i] += round*num_people+(i+1);
                candies -= round*num_people+(i+1);
            }
            round += 1;
        }
        return ans;
    }
};