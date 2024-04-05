#include<string>
using namespace std;
class Solution {
public:
    long long countSubstrings(string s, char c) {
        int char_cnt = 0;
        for(auto&ch : s){
            if(ch == c) char_cnt += 1;
        }
        
        long long ans = 0;
        for(int i=0; i<char_cnt; i++){
            ans += (i+1);
        }
        return ans;
    }
};