#include <vector>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end(),[](int a, int b){
            return a > b;
        });

        auto sz = citations.size();
        int idx = 0;
        for(int h_val=sz; h_val >=0; h_val--){
            while(idx < sz && h_val <= citations[idx]) idx += 1;
            if(idx >= h_val) return h_val;
        }
        return 0;
    }
};