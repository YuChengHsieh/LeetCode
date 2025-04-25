#include <vector>
#include <map>
#include <string>
using namespace std;
class Solution {
    private:
        bool check(vector<int>& vowels, int k){
            return vowels[0] >= 1 && vowels[1] >= 1 && vowels[2] >= 1 && vowels[3] >= 1 && vowels[4] >= 1 && vowels[5] >= k;
        }
        long long slidingWindow(string word, int k){
            map<char,int> mp = {
                {'a',0},
                {'e',1},
                {'i',2},
                {'o',3},
                {'u',4},
            };
            vector<int> vowels(6,0);
            long long ans = 0;
            int left = 0;
            for(int i=0; i<word.size(); i++){ 
                if(mp.count(word[i])){
                    vowels[mp[word[i]]]++;
                }else vowels[5]++;
    
                while(check(vowels,k)){
                    if(mp.count(word[left])){
                        vowels[mp[word[left]]]--;
                    }else vowels[5]--;
                    left++;
                } 
                ans += left;
            }
            return ans;
        }
    public:
        long long countOfSubstrings(string word, int k) {
            return slidingWindow(word, k) - slidingWindow(word, k+1);
        }
    };