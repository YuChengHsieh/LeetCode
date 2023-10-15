#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <numeric>

using namespace std;
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> flowers_start ;
        vector<int> flowers_end;

        for(auto &i:flowers){
            flowers_start.push_back(i[0]);
            flowers_end.push_back(i[1]);
        }

        sort(flowers_start.begin(), flowers_start.end());
        sort(flowers_end.begin(), flowers_end.end());

        vector<int> ans;
        for (int person : people) {
            int start = upper_bound(flowers_start.begin(), flowers_start.end(),person) - flowers_start.begin();
            int end = lower_bound(flowers_end.begin(), flowers_end.end(),person) - flowers_end.begin();
            ans.push_back(start - end);
        }
        return ans;
    }
};