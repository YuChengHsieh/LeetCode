#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;
class Solution {
public:
    int countVowelSubstrings(string word) {
        // brutal force
        int n = word.size();
        int cnt = 0;
        unordered_set<char> vowel {'a','e','i','o','u'};
        for(int i=0; i<=n-5; i++){
            if(vowel.count(word[i]) != 1) continue;
            unordered_set<char> tmp {word[i]};
            for(int j=i+1; j<n; j++){
                if(vowel.count(word[j]) != 1) break;
                tmp.insert(word[j]);
                if(tmp.size() == vowel.size()) cnt += 1;
            }
        }
        return cnt;
    }
};