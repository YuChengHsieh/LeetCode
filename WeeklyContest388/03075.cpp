#include<vector>
using namespace std;
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), [](int a, int b){
            return a > b; 
        });
        long long ans = 0;
        for(int i=0; i<k; i++){
            ans += max(0,happiness[i]-i);
        }
        return ans;
    }
};