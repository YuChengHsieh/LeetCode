#include <vector>
#include <map>
#include <string>
using namespace std;

// sliding window
class Solution {
    private:
        bool check(vector<int>& cnt){
            return cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0;
        }
    public:
        int numberOfSubstrings(string s) {
            map<char,int> mp = {
                {'a', 0},
                {'b', 1},
                {'c', 2}
            };
            vector<int> cnt(3,0);
            int left = 0, ans = 0;
            for(int i=0; i<s.size(); i++){
                cnt[mp[s[i]]] ++;
                while(check(cnt)){
                    cnt[mp[s[left]]] --;
                    left++;
                } 
                ans += left;
            }
            return ans;
        }
    };