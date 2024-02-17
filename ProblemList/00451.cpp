#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char,int>> count(100,pair<char,int>());
        
        for(int i=0; i<100; i++){
            count[i] = make_pair('0'+i,0);
        }

        for(auto &ch: s){
            count[ch-'0'].second += 1;
        }

        sort(count.begin(),count.end(),[](pair<char,int> a, pair<char,int> b){
            return a.second > b.second;
        });

        string ans;
        for(auto &item: count){
            if(item.second == 0) break;
            for(int i=0; i<item.second; i++){
                ans += item.first;
            }
        }
        return ans;

    }
};