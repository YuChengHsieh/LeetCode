#include <unordered_set>
#include <string>
using namespace std;
class Solution {
public:
    bool halvesAreAlike(string s) {
        int first_vowel_cnt = 0, second_vowel_cnt = 0;
        unordered_set<char> vowel_set {'a','e','i','o','u','A','E','I','O','U'};
        for(int i=0; i<s.size()/2; i++){
            if(vowel_set.count(s[i])) first_vowel_cnt += 1;
        }
        for(int i=s.size()/2; i<s.size(); i++){
            if(vowel_set.count(s[i])) second_vowel_cnt += 1;
        }
        return first_vowel_cnt == second_vowel_cnt;
    }
};