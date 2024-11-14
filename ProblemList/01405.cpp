#include <string>
using namespace std;
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int cnt_straight = 0; char last = '-'; 
        string ans;
        while(true){
            if(a > 0 && a >= c && a >= b){
                if(last == 'a' && cnt_straight == 2){
                    if(b == 0 && c == 0) break;
                    if(c > b){
                        ans += 'c';
                        last = 'c';
                        c --;
                    }else{
                        ans += 'b';
                        last = 'b';
                        b --;
                    }
                }else{
                    cnt_straight = last == 'a' ? cnt_straight + 1 : 1;
                    ans += 'a';
                    last = 'a';
                    a --;
                }
            }else if(b > 0 && b >= c && b >= a){
                if(last == 'b' && cnt_straight == 2){
                    if(c == 0 && a == 0) break;
                    if(a > c){
                        ans += 'a';
                        last = 'a';
                        a --;
                    }else{
                        ans += 'c';
                        last = 'c';
                        c --;
                    }
                }else{
                    cnt_straight = last == 'b' ? cnt_straight + 1 : 1;
                    ans += 'b';
                    last = 'b';
                    b --;
                }   
            }else if(c > 0 && c >= b && c >= a){
                if(last == 'c' && cnt_straight == 2){
                    if(a == 0 && b == 0) break;
                    if(a > b){
                        ans += 'a';
                        last = 'a';
                        a --;
                    }else{
                        ans += 'b';
                        last = 'b';
                        b --;
                    }
                }else{
                    cnt_straight = last == 'c' ? cnt_straight + 1 : 1;
                    ans += 'c';
                    last = 'c';
                    c --;
                }
                
            }else break;
        }
        return ans;
    }
};