#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string,int> cnts;
        int max_val = 0;
        for(int i=0; i<word.size(); i+=k){
            cnts[word.substr(i,k)] += 1;
            max_val = max(max_val, cnts[word.substr(i,k)]);
        }
        return word.size()/k - max_val;
    }
};