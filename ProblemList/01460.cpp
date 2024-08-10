#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int,int> mp1;
        map<int,int> mp2;

        for(int i=0; i<target.size(); i++){
            mp1[target[i]] += 1;
            mp2[arr[i]] += 1;
        }
        return mp1 == mp2;
    }
};