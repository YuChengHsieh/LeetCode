#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int> str_cnts;
        for(auto&s : arr){
            str_cnts[s] += 1;
        }
        int cnt = 0;
        for(auto&s : arr){
            if(str_cnts[s] == 1){
                cnt += 1;
                if(cnt == k) return s;
            }
        }
        return "";
    }
};