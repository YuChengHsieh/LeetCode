#include <string>
using namespace std;
class Solution {
public:
    int maxVowels(string s, int k) {
        int vowel_cnt = 0;
        for(int i=0; i<k; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') vowel_cnt += 1;
        }

        int left = 0, max_vowel_cnt = vowel_cnt; 
        for(int i=k; i<s.size(); i++){
            if(s[left] == 'a' || s[left] == 'e' || s[left] == 'i' || s[left] == 'o' || s[left] == 'u' ) vowel_cnt -= 1;
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') vowel_cnt += 1;
            max_vowel_cnt = max(max_vowel_cnt,vowel_cnt);
            left += 1;
        }
        return max_vowel_cnt;
    }
};