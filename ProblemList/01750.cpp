#include <string>
using namespace std;
class Solution {
public:
    int minimumLength(string s) {
        int start_idx = 0, end_idx = s.size()-1;
        while(start_idx < end_idx && s[start_idx] == s[end_idx]){
            while(start_idx < end_idx && s[start_idx+1] == s[start_idx]) start_idx ++;
            while(start_idx < end_idx && s[end_idx-1] == s[end_idx]) end_idx --;
            start_idx ++;
            end_idx --;
            // cout << s.substr(start_idx,end_idx-start_idx+1) << endl;
        }
        return end_idx - start_idx >= 0 ? end_idx - start_idx + 1 : 0 ;
    }
};