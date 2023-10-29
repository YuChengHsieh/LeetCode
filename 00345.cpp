#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<int> vowel {'a','e','i','o','u','A','E','I','O','U'};
        int left = 0, right = s.size()-1;
        while(true){
            while(left < right && vowel.find(s[left]) == vowel.end()) left += 1;
            while(left < right && vowel.find(s[right]) == vowel.end()) right -= 1;
            if(left >= right) break;

            swap(s[left],s[right]);
            left += 1; right -= 1;
        }
        return s;
    }
};