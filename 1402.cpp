# include<iostream>
# include<vector>
using namespace std;
// use prefix sum
class Solution {
public:
    static bool cmp(int i, int j){return(i>j);}
    int maxSatisfaction(vector<int>& satisfaction) {
        // sort
        sort(satisfaction.begin(),satisfaction.end(),cmp);
        int prefix_sum = 0,sum = 0;
        for(int i=0; i<satisfaction.size(); i++){
            prefix_sum += satisfaction[i];

            if(prefix_sum<0) break;
            sum += prefix_sum;
        }
        return sum;
    }
};