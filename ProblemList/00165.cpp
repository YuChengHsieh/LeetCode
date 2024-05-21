#include <string>
using namespace std;
class Solution {
public:
    int compareVersion(string v1, string v2) {
        int v1_idx = 0, v2_idx = 0, v1_sz = v1.size(), v2_sz = v2.size();
        while(v1_idx < v1_sz || v2_idx < v2_sz){
            string tv1 = "0", tv2 = "0";
            while(v1_idx < v1_sz && v1[v1_idx] != '.') tv1 += v1[v1_idx++];
            while(v2_idx < v2_sz && v2[v2_idx] != '.') tv2 += v2[v2_idx++];
            v1_idx ++; v2_idx++;
            if(stoi(tv1) > stoi(tv2)) return 1;
            else if(stoi(tv1) < stoi(tv2)) return -1;
        }
        return 0;
    }
};