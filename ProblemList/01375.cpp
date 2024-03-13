#include<set>
#include<vector>
using namespace std;

// time complexity: ~o(n), space complexity o(n)
class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        set<int> s;
        for(int i=0; i<flips.size(); i++){
            s.insert(i);
        }

        int ans = 0;
        for(int i=0; i<flips.size(); i++){
            s.erase(flips[i]-1);
            if(i == flips.size() - 1 || i+1 <= *s.begin()) ans ++;
        }
        return ans;
    }
};

// time complexity o(n), space complexity o(1)
class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int right = 0;
        int cnt = 0;
        for(int i=0; i<flips.size(); i++){
            right = max(right, flips[i]);
            if(right == i+1) cnt ++;
        }
        return cnt;
    }
};