#include <string>
using namespace std;
class Solution {
public:
    string compressedString(string word) {
        char prev = ' ';
        int cnt = 1;
        string ans;
        for(int i=0; i<word.size(); i++){
            if(word[i] == prev){
                cnt += 1;
            } 
            else{
                if(prev != ' '){
                    ans += cnt+'0';
                    ans += prev;
                    cnt = 1;
                } 
            }
            if(cnt > 9){
                ans += cnt-1+'0';
                ans += prev;
                cnt = 1;
            }
            prev = word[i];
        }
        
        ans += cnt+'0';
        ans += prev;
        cnt = 1;
        return ans;
    }
};